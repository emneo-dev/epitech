##
## EPITECH PROJECT, 2019
## my_popup
## File description:
## The Makefile for BSQ
##

CC		=	gcc

SRC 	=	my_popup.c	\

OBJ 	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -pedantic -fno-builtin -Werror

LIB_FLAGS 	=	-lncurses

TARGET	=	my_popup

all:	target

target: $(OBJ)
	@printf "\e[1;32mFinished compiling sources\e[0m\n"
	@$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) $(LIB_FLAGS)
	@printf "[\e[1;33mLinked\e[0m] % 33s\n" $(OBJ) | tr ' ' '.'
	@printf "\e[1;32mLinked all object files\e[0m\n"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "[\e[1;34mCompiled\e[0m] % 31s\n" $< | tr ' ' '.'

clean:
	@rm -f $(OBJ)
	@printf "[\e[1;31mRemoved\e[0m] % 32s\n" $(OBJ) | tr ' ' '.'
	@printf "\e[1;32mFinished removing objects\e[0m\n"


fclean: clean
	@rm -f $(TARGET)
	@printf "[\e[1;31mRemoved\e[0m] % 32s\n" $(TARGET) | tr ' ' '.'
	@printf "\e[1;32mFinished removing linked binaries\e[0m\n"

re:	fclean all
