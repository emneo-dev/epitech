##
## EPITECH PROJECT, 2019
## my_exec
## File description:
## The Makefile for my_exec
##

SRC 	=	src/exec/my_exec.c	\
			src/exec/str_to_word_array.c	\
			src/exec/my_putstr.c	\
			src/exec/my_strlen.c	\
			src/exec/my_strcpy.c	\
			src/exec/my_strcpy_arr.c	\
			src/exec/my_put_nbr.c	\
			src/exec/my_putchar.c	\

OBJ 	=	$(SRC:.c=.o)

MAIN_SRC	=	src/main.c 	\

MAIN_OBJ	=	$(MAIN_SRC:.c=.o)

CFLAGS	=	-I./include -Wall -Wextra -Werror

COVERAGE	=	$(SRC:.c=.gcda)	\
				$(SRC:.c=.gcno)	\
				$(MAIN_SRC:.c=.gcno)	\
				$(MAIN_SRC:.c=.gcno)	\

TARGET	=	my_exec

all:	$(TARGET)

$(TARGET): build

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "[\e[1;34mCompiled\e[0m] % 41s\n" $@ | tr ' ' '.'

build: $(OBJ) $(MAIN_OBJ)
	@printf "\e[1;32mFinished compiling sources\e[0m\n"
	@$(CC) $(OBJ) $(MAIN_OBJ) -o $(TARGET)
	@printf "[\e[1;33mLinked\e[0m] % 43s\n" $(OBJ) | tr ' ' '.'
	@printf "[\e[1;33mLinked\e[0m] % 43s\n" $(MAIN_OBJ) | tr ' ' '.'
	@printf "\e[1;32mLinked all object files\e[0m\n"

clean:
	@rm -f $(OBJ) $(MAIN_OBJ) $(COVERAGE)
	@printf "[\e[1;31mRemoved\e[0m] % 42s\n" $(OBJ) | tr ' ' '.'
	@printf "\e[1;32mFinished removing objects\e[0m\n"

fclean: clean
	@rm -f $(TARGET)
	@printf "[\e[1;31mRemoved\e[0m] % 42s\n" $(TARGET) | tr ' ' '.'
	@printf "\e[1;32mFinished removing linked binaries\e[0m\n"

re:	fclean all

valgrind: all
	@valgrind --leak-check=full --show-leak-kinds=all ./my_runner a

.PHONY:	re fclean clean build all