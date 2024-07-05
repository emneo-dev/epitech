##
## EPITECH PROJECT, 2019
## CPool_Day11_2019
## File description:
## The Makefile for the day which compile and run the tests if needed
##

SRC 	=		my_params_to_list.c	\
				my_list_size.c	\
				my_rev_list.c	\
				my_apply_on_nodes.c	\
				my_apply_on_matching_nodes.c	\
				my_delete_nodes.c	\

TEST	=		tests/test_my_params_to_list.c	\
				tests/test_my_list_size.c	\
				tests/test_my_rev_list.c	\
				tests/test_my_apply_on_nodes.c	\

OBJ 	=		$(SRC:.c=.o)

NAME	=		linked_list

NAME_TEST	=	unit-test

all:	$(NAME)

$(NAME):
		gcc -o $(NAME) $(SRC) -I./include -L./lib/my -lmy

clean:
		rm -f $(OBJ)
		rm -f *.gc*

fclean: clean
		rm -f $(NAME)

re:		fclean all

tests_run:
		gcc -o $(NAME_TEST) $(SRC) $(TEST) -I./include -L./lib/my -lmy -lcriterion --coverage
		./$(NAME_TEST)
		gcovr --exclude tests/
