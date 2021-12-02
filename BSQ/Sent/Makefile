SRC=./srcs/*.c
INCLUDES=./includes
OBJS=*.o

all:
	make out

out:
	gcc -Wall -Wextra -Werror -I$(INCLUDES) $(SRC) -o bsq

clean:
	rm -f bsq

re:
	make clean
	make all

.PHONY: clean all out re
