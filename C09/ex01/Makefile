# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reclaire <reclaire@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 21:01:30 by reclaire          #+#    #+#              #
#    Updated: 2021/12/01 21:07:18 by reclaire         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=./srcs/
SRCS=$(SRC)ft_putchar.c $(SRC)ft_swap.c $(SRC)ft_putstr.c $(SRC)ft_strlen.c $(SRC)ft_strcmp.c
INCLUDES=./includes/
OBJS=${SRCS:.c=.o}

.c.o:
	gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $< -o $(<:.c=.o)

all:
	make libft.a

libft.a: $(OBJS)
	ar rc libft.a $(OBJS)

clean:
	find $(SRC) -type f -name "*.o" -delete	

fclean:
	make clean
	rm -f libft.a

re:
	make fclean
	make all

.PHONY: clean all libft.a fclean re
