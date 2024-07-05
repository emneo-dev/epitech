##
## EPITECH PROJECT, 2019
## CPool_infinadd_2019
## File description:
## The Makefile for the infinadd project
##

SRC 	=	src/parse_args.c	\
			src/sort_nbr_str.c	\
			src/add_positives.c	\
			src/is_negative.c	\
			src/add_negatives.c	\

OBJ 	=	$(SRC:.c=.o)

NAME	=	infin_add

NAME_TEST	=	unit-test

FLAGS	=	-I./include -L./lib/my -lmy

FLAGS_TEST	=	-lcriterion --coverage

all:	$(NAME)

$(NAME):
	cd lib/my && make re
	gcc -o $(NAME) src/main.c $(SRC) $(FLAGS)

clean:
	rm -f $(OBJ)
	rm -f *.gc*

fclean:	clean
	rm -f $(NAME)

re:	fclean all
