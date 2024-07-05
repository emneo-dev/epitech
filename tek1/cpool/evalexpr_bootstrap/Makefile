##
## EPITECH PROJECT, 2019
## CPool_infinadd_2019
## File description:
## The Makefile for the infinadd project
##

SRC 	=	src/eval_expr.c	\
			src/number.c	\
			src/summands.c	\

OBJ 	=	$(SRC:.c=.o)

NAME	=	evalexpr_bootstrap

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
