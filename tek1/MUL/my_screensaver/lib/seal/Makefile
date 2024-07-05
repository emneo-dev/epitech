##
## EPITECH PROJECT, 2019
## libmy
## File description:
## The Makefile for libmy
##

CC		=	gcc

SRC 	=	src/sl_init.c	\
		src/sl_play.c	\
		src/sl_framebuffer_create.c	\
		src/sl_put_pixel.c 	\
		src/sl_put_rectangle.c 	\

#TEST_SRC	=	tests/test_my_printf.c	\

OBJ 	=	$(SRC:.c=.o)

#TEST_OBJ	=	$(TEST_SRC:.c=.o)

CFLAGS	=	-W -I./include -Wall -Wextra -pedantic -fno-builtin -Werror

#TEST_CFLAGS	=	-lcriterion

#LIB_FLAGS	=	-L. -l

TARGET	=	libseal.a

#TARGET_TEST	=	unit_tests

all:	$(TARGET)

$(TARGET): $(OBJ)
	@printf "\e[1;32mFinished compiling sources\e[0m\n"
	@ar rc $(TARGET) $(OBJ)
	@printf "[\e[1;33mLinked\e[0m] % 33s\n" $(OBJ) | tr ' ' '.'
	@printf "\e[1;32mLinked all object files\e[0m\n"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "[\e[1;34mCompiled\e[0m] % 31s\n" $< | tr ' ' '.'

clean:
	@rm -f $(OBJ) $(TEST_OBJ)
	@printf "[\e[1;31mRemoved\e[0m] % 32s\n" $(OBJ) | tr ' ' '.'
	@printf "\e[1;32mFinished removing objects\e[0m\n"

tests_run: all
	@$(CC) $(CFLAGS) $(TEST_CFLAGS) -o $(TARGET_TEST) $(TEST_SRC) $(LIB_FLAGS)
	@printf "[\e[1;34mCompiled\e[0m] % 31s\n" $(TEST_SRC) | tr ' ' '.'
	@printf "\e[1;32mFinished compiling tests...\e[0m\n"
	@printf "\e[1;32mLaunching tests...\e[0m\n"
	@./unit_tests

fclean: clean
	@rm -f $(TARGET) $(TARGET_TEST)
	@printf "[\e[1;31mRemoved\e[0m] % 32s\n" $(TARGET) | tr ' ' '.'
	@printf "[\e[1;31mRemoved\e[0m] % 32s\n" $(TARGET_TEST) | tr ' ' '.'
	@printf "\e[1;32mFinished removing linked binaries\e[0m\n"

re:	fclean all

re_tests: re tests_run
