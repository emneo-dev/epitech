##
## EPITECH PROJECT, 2019
## CPool_Day12_2019
## File description:
## The Makefile for the cat replica
##

SRC 	=		cat.c	\

TEST	=		tests/test_cat.c	\

OBJ 	=		$(SRC:.c=.o)

NAME	=		cat

NAME_TEST	=	unit-test

all:	$(NAME)

$(NAME):
		cd ../lib/my && make
		gcc -o $(NAME) $(SRC) main.c -I../include -L../lib/my -lmy

clean:
		rm -f $(OBJ)
		rm -f *.gc*

fclean: clean
		rm -f $(NAME)

re:		fclean all

tests_run:
		gcc -o $(NAME_TEST) $(SRC) $(TEST) -I../include -L../lib/my -lmy -lcriterion --coverage
		./$(NAME_TEST)
		gcovr --exclude tests/
