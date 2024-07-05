##
## EPITECH PROJECT, 2019
## CPool_finalstumper_2019
## File description:
## The Makefile for the finalstumper project
##

SRC 	=	src/rush3.c	\
			src/get_ex.c	\
			src/get_length.c	\
			src/is_just_b.c	\
			src/is_first.c	\
			src/is_second.c	\
			src/is_third.c	\
			src/is_fourth.c	\
			src/is_fifth.c	\
			src/is_just_star.c	\

TEST	=	tests/test_rush3.c	\

OBJ 	=	$(SRC:.c=.o)

NAME	=	rush3

NAME_TEST	=	unit-test

FLAGS	=	-I./include -L./lib/my -lmy

FLAGS_TEST	=	-lcriterion --coverage

all:	$(NAME)

$(NAME):
	cd lib/my && make re
	gcc -o $(NAME) src/main.c $(SRC) $(FLAGS) -g3

clean:
	rm -f $(OBJ)
	rm -f *.gc*

fclean:	clean
	rm -f $(NAME)

re:	fclean all

tests_run:
	cd lib/my && make re
	gcc -o $(NAME_TEST) $(SRC) $(TEST) $(FLAGS) $(FLAGS_TEST)
	./$(NAME_TEST)
	gcovr
