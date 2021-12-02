setopt histignorespace

setupproj()
{
	if [[ "$#" < 3 || "$#" > 3 ]]
	then 
		echo "setupproj: invalid argument"
		echo "usage: (project name) (nb of ex) (git url)"
		return 0;
	fi

	mkdir "$@[1]"
	for i in $(seq -w 0 $2) ; do mkdir "ex$i"; done
	cd "$@[1]"
	git init
	stderr=$(git remote add origin "$@[3]")
	if [[ $stderr == "*fatal*" ]]
	then
		echo "setupproj: git error:"
		echo $stderr
	fi
}

repeatchar() {
	for i in {1..$2}; do echo -n "$1"; done
}

up() {
	echo -e -n '\e[1A\e[K'

	dirnamePWD=$(dirname $PWD)
	pwdls=$(ls -ld ../*/ | sed 's@.* @@')

	arr=()
	while IFS= read -r -d $'\n'; do
		arr+=$(basename $REPLY)
	done <<<$pwdls

	index=-1
	for (( i=1; i<=${#arr}; i++ ));
	do
		if [[ "${arr[$i]}" = $(basename $PWD) ]];
    	then
        	index=$i
    	fi
	done

	if [ $index = 1 ]
	then index=${#arr}
	else index=$(expr $index - 1)
	fi

	cd "../${arr[$index]}"
}

down() {
	echo -e -n '\e[1A\e[K'

    dirnamePWD=$(dirname $PWD)
    pwdls=$(ls -ld ../*/ | sed 's@.* @@')

    arr=()
    while IFS= read -r -d $'\n'; do
        arr+=$(basename $REPLY)
    done <<<$pwdls

    index=-1
    for (( i=1; i<=${#arr}; i++ ));
    do
        if [[ "${arr[$i]}" = $(basename $PWD) ]];
        then
            index=$i
        fi
    done

    if [ $index = ${#arr} ]
    then index=1
    else index=$(expr $index + 1)
    fi

    cd "../${arr[$index]}"
}

readyforeval() {
	argv=("$@")
	gccflags=()

	removeoutput=0

	for (( i=1; i<=$#; i++ )); do
		case "${argv[i]}" in
			"-gcc-flags")
				j=$(expr $i + 1)
				while [ "${argv[j]}" != "" -o "${argv[j]}" != "-*" ];
				do
					if (($j > $#))
					then break
					fi
					gccflags+=(-t "-${argv[j]}")
					j=$(expr $j + 1)
				done
				;;
			"-rm-output")
				removeoutput=1
				;;
			"-no-git-ign")
				nogitign=1
				;;
			"-no-ign-main")
				noignmain=1
				;;
			"-help")
				echo "usage: readyforeval   [ -gcc-flag  ]  [   -rm-output  ]  [      -no-git-ign      ]  [       -no-ign-main    ]  [     -help     ]"
				echo "                      Compiler flags  Remove .out files  Don't create a .gitignore  Don't ignore main.c files  Show help message"
				return 0;
				;;
		esac
	done

	if [ $removeoutput = 1 ]
	then
		printf "%0.s=" $(seq 1 $(expr $COLUMNS / 2 - 12))
		echo -n " Removing .out files "
		printf "%0.s=" $(seq 1 $(expr $COLUMNS / 2 - 12))

		find . -type f -name '*.out' -print -delete
	fi

	array=()
	while IFS=  read -r -d $'\0'; do
		if [[ "$REPLY" == "main.c"  ]]
		then ignoredmess="main.c files ignored !"
		else array+=("$REPLY")
		fi
	done < <(find . -name "*.c" -print0)	

	arraylength=${#array[@]}
	if [[]]

	maxfilelength=0
	for (( i=1; i<${arraylength}; i++ ));
	do
		if (( $maxfilelength < ${#${array[$i]}} ))
		then maxfilelength=${#${array[$i]}}
		fi
	done

	maxfilelength=$(expr $maxfilelength + 5)

	printf "%0.s=" $(seq 1 $(expr $COLUMNS / 2 - 12))
	echo -n " Searching for mains "
	printf "%0.s=" $(seq 1 $(expr $COLUMNS / 2 - 12))
	echo ""

	currentmaxlength=$(expr $maxfilelength + 23)
	for (( i=1; i<${arraylength}; i++ ));
	do
		s1="Searching in ${array[$i]}"
		if grep -xq "main(" "${array[$i]}"
		then
			s2="Main found !"
		else
			s2="OK !"
		fi
		if grep -xq "printf(" "${array[$i]}"
		then
			echo "TEEEEEST"
			s2="$s2\n$(repeatchar $currentmaxlength " ") Printf found !"
		fi
		printf "%-${currentmaxlength}s %-13s\n" "$s1" "$s2"
	done

	printf "%0.s=" $(seq 1 $(expr $COLUMNS / 2 - 6))
	echo -n " Norminette "
	printf "%0.s=" $(seq 1 $(expr $COLUMNS / 2 - 6))
	echo ""

	for (( i=1; i<${arraylength}; i++ ));
	do
		s1="Executing norminette in ${array[i]}"
		normcmd=$(norminette ${array[i]})
		if [[ "$normcmd" == *"OK!"* ]];
		then
			s2="OK !"
		else
			s2="Norm error !"
		fi
		printf "%-${currentmaxlength}s %-12s\n" "$s1" "$s2"
	done
	

	printf "%0.s=" $(seq 1 $(expr $COLUMNS / 2 - 2))
	echo -n " GCC "
	printf "%0.s=" $(seq 1 $(expr $COLUMNS / 2 - 2))
	echo ""

	if (( ${#gccflags} > 0 ))
	then printf "    -> Flags used for compiler: $gccflags\n"
	fi
	printf "    -> Created temporary main.c in ./tmp\n"

	mkdir ./tmp
	touch ./tmp/main.c

	echo "
int main() {
	return 0;
}
	" >> ./tmp/main.c

	for (( i=1; i<${arraylength}; i++ ));
	do
		s1="Trying to compile ${array[i]}"
		
		filename=$(basename ${array[i]})

		cmdoutput=$((gcc ${gccflags[@]} ./tmp/main.c ${array[i]} >&2) 2>&1)
		
		if (( ${#cmdoutput} > 0 ))
		then
			s2="Compiler error !"
		else
			s2="OK !"
		fi
		printf "%-${currentmaxlength}s %-12s\n" "$s1" "$s2"
	done
	
	rm ./tmp/main.c
	rm ./tmp/delete_on_sight
	rmdir ./tmp
}
