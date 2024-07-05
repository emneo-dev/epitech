##
## EPITECH PROJECT, 2019
## CPE_solostumper_2_2019
## File description:
## The Makefile CPE_solostumper_2_2019
##

SRC 	=	src/stumper/rrostring.c	\
		src/stumper/str_to_word_array.c	\
		src/stumper/my_strcpy.c	\
		src/stumper/my_strlen.c	\
		src/stumper/my_putstr.c	\

OBJ 	=	$(SRC:.c=.o)

MAIN_SRC	=	src/main.c 	\

MAIN_OBJ	=	$(MAIN_SRC:.c=.o)

CFLAGS	=	-I./include -Wall -Wextra

TARGET	=	rrostring

all:	$(TARGET)

$(TARGET): build

build: $(OBJ) $(MAIN_OBJ)
	$(CC) $(OBJ) $(MAIN_OBJ) -o $(TARGET) $(LFLAGS)

clean: clean_lib
	rm -f $(OBJ) $(MAIN_OBJ) $(COVERAGE)

fclean: fclean_lib clean
	rm -f $(TARGET)

re:	fclean all

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all ./my_runner a

.PHONY:	re fclean clean fclean_lib clean_lib build build_lib all
