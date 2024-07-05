SRC	=	do-op.c	\
		multiply_substract.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	do-op

all:	$(NAME)

$(NAME):
		gcc -o $(NAME) $(SRC) -I../include -L../lib -lmy

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all
