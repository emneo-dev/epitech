OBJ 	=		$(SRC:.c=.o)

NAME	=		rush2

all:	$(NAME)

$(NAME):
		gcc -o $(NAME) *.c

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all
