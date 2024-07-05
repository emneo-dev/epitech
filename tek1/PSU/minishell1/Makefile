##
## EPITECH PROJECT, 2020
## PSU_minishell1_2019 [WSL: Debian]
## File description:
## Makefile
##

SHELL		=		bash

SRC			=		src/sh/sh.c			\
					src/sh/handle_input.c	\
					src/sh/print_prompt.c	\
					src/sh/is_a_builtin.c	\
					src/sh/handle_builtin.c	\
					src/sh/handle_cmd.c	\
					src/sh/builtins/sh_exit.c	\
					src/sh/builtins/sh_env.c	\
					src/sh/builtins/sh_setenv.c	\
					src/sh/builtins/sh_unsetenv.c	\
					src/sh/builtins/sh_cd.c	\
					src/sh/env_cpy.c	\
					src/sh/my_ll_len.c	\
					src/sh/my_exec.c	\
					src/sh/path_exec.c	\
					src/sh/append_path.c	\
					src/sh/my_split_cpy.c	\
					src/sh/my_str_split.c	\
					src/sh/get_splited_path.c	\
					src/sh/handle_incoming_pipe.c	\
					src/sh/append.c	\

MAIN_SRC	=		src/main.c					\

OBJ			=		$(SRC:.c=.o)

MAIN_OBJ	=		$(MAIN_SRC:.c=.o)

TEST_SRC	=	tests/test_print_prompt.c	\
				tests/test_is_a_builtin.c	\
				tests/test_sh_exit.c	\
				tests/test_sh_env.c	\
				tests/test_env_cpy.c	\
				tests/test_my_str_split.c	\
				tests/test_append_path.c	\
				tests/test_append.c	\
				tests/test_my_ll_len.c	\
				tests/test_get_splited_path.c	\
				tests/test_sh_setenv.c	\
				tests/test_sh_unsetenv.c	\

TEST_OBJ	=	$(TEST_SRC:.c=.o)

CFLAGS		=		-I./include/ -Wall -Wextra -Werror

LFLAGS		=		-L./lib -lmy

TEST_LFLAGS	=	-lcriterion

COVERAGE	=	$(SRC:.c=.gcda)	\
				$(SRC:.c=.gcno)	\
				$(MAIN_SRC:.c=.gcda)	\
				$(MAIN_SRC:.c=.gcno)	\
				$(TEST_SRC:.c=.gcno)	\
				$(TEST_SRC:.c=.gcda)	\

TARGET		=		mysh

TARGET_TEST		=		unit_tests

#-------------------------------------------------------------------------------

all:	$(TARGET)

$(TARGET): build_lib build

build_lib:
	@$(MAKE) -C ./lib/libmy --silent
	@cp ./lib/libmy/libmy.a ./lib/libmy.a
	@cp ./lib/libmy/include/my.h ./include/my.h

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "[\e[1;34mCompiled\e[0m] % 41s\n" $@ | tr ' ' '.'

build: $(OBJ) $(MAIN_OBJ)
	@printf "\e[1;32mFinished compiling sources\e[0m\n"
	@$(CC) $(OBJ) $(MAIN_OBJ) -o $(TARGET) $(LFLAGS)
	@printf "[\e[1;33mLinked\e[0m] % 43s\n" $(OBJ) | tr ' ' '.'
	@printf "[\e[1;33mLinked\e[0m] % 43s\n" $(MAIN_OBJ) | tr ' ' '.'
	@printf "\e[1;32mLinked all object files\e[0m\n"

clean_lib:
	@$(MAKE) -C lib/libmy/ --silent clean

fclean_lib:
	@$(MAKE) -C lib/libmy/ --silent fclean
	@rm -f lib/libmy.a

clean: clean_lib
	@rm -f $(OBJ) $(MAIN_OBJ) $(COVERAGE) $(TEST_OBJ)
	@printf "[\e[1;31mRemoved\e[0m] % 42s\n" $(OBJ) | tr ' ' '.'
	@printf "[\e[1;31mRemoved\e[0m] % 42s\n" $(MAIN_OBJ) | tr ' ' '.'
	@printf "[\e[1;31mRemoved\e[0m] % 42s\n" $(COVERAGE) | tr ' ' '.'
	@printf "[\e[1;31mRemoved\e[0m] % 42s\n" $(TEST_OBJ) | tr ' ' '.'
	@printf "\e[1;32mFinished removing objects\e[0m\n"

fclean: fclean_lib clean
	@rm -f $(TARGET) $(TARGET_TEST)
	@printf "[\e[1;31mRemoved\e[0m] % 42s\n" $(TARGET) | tr ' ' '.'
	@printf "[\e[1;31mRemoved\e[0m] % 42s\n" $(TARGET_TEST) | tr ' ' '.'
	@printf "\e[1;32mFinished removing linked binaries\e[0m\n"

re:	fclean all

tests_run: CFLAGS += --coverage ## Launch tests
tests_run: build_lib $(OBJ) $(TEST_OBJ)
	@printf "\e[1;32mFinished compiling sources\e[0m\n"
	@$(CC) $(CFLAGS) $(OBJ) $(TEST_OBJ) -o $(TARGET_TEST) $(LFLAGS) $(TEST_LFLAGS)
	@printf "[\e[1;33mLinked\e[0m] % 43s\n" $(OBJ) | tr ' ' '.'
	@printf "[\e[1;33mLinked\e[0m] % 43s\n" $(TEST_OBJ) | tr ' ' '.'
	@printf "\e[1;32mLaunching tests...\e[0m]\n"
	@./$(TARGET_TEST)
	@gcovr --exclude tests/
	@gcovr --branches --exclude tests/

re_tests: fclean tests_run ## Force clean then launch tests

valgrind: all
	@valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

.PHONY:	re fclean clean fclean_lib clean_lib build build_lib all tests_run re_tests help valgrind