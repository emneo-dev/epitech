##
## EPITECH PROJECT, 2019
## CPool_infinadd_2019
## File description:
## The Makefile for the infinadd project
##

SRC 	=	src/eval_expr.c	\
			src/get_next_info.c	\
			src/get_rpn_expr.c	\
			src/push_number.c	\
			src/push_token.c	\
			src/put_node_to_list.c	\
			src/push_stack_to_output.c	\
			src/get_precedence.c	\

OBJ 	=	$(SRC:.c=.o)

NAME	=	eval_expr

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
