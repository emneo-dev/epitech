##
## EPITECH PROJECT, 2019
## BSQ
## File description:
## The Makefile for BSQ
##

CC		=	gcc

SRC 	=	swap_elem.c	\
		bubble_sort_array.c 	\

TEST_SRC	=	tests/test_swap_elem.c	\
			tests/test_bubble_sort_array.c 	\

OBJ 	=	$(SRC:.c=.o)

TEST_OBJ	=	$(TEST_SRC:.c=.o)

CFLAGS	=	--coverage -I./include -Wall -Wextra -pedantic -fno-builtin -Werror

TEST_CFLAGS	=	-lcriterion

LIB_FLAGS	=	-L./lib -lmy

TARGET_TEST	=	unit_tests

all:	target

target: $(OBJ)
	@printf "\e[1;32mFinished compiling sources\e[0m\n"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "[\e[1;34mCompiled\e[0m] % 31s\n" $< | tr ' ' '.'

clean:
	@rm -f $(OBJ) $(TEST_OBJ) *.gcda *.gcno tests/*.gcda tests/*.gcno
	@printf "[\e[1;31mRemoved\e[0m] % 32s\n" $(OBJ) $(TEST_OBJ) *.gcda *.gcno tests/*.gcda tests/*.gcno | tr ' ' '.'
	@printf "\e[1;32mFinished removing objects\e[0m\n"


test_build: $(OBJ) $(TEST_OBJ)
	@printf "\e[1;32mFinished compiling sources\e[0m\n"

tests_run: test_build
	@$(CC) $(CFLAGS) $(TEST_CFLAGS) $(OBJ) $(TEST_OBJ) -o $(TARGET_TEST)
	@printf "\e[1;32mLaunching tests...\e[0m\n"
	@./unit_tests
	@gcovr --exclude tests/

fclean: clean
	@rm -f $(TARGET_TEST)
	@printf "[\e[1;31mRemoved\e[0m] % 32s\n" $(TARGET_TEST) | tr ' ' '.'
	@printf "\e[1;32mFinished removing linked binaries\e[0m\n"

re:	fclean all

re_tests: re tests_run
