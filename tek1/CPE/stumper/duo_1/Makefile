##
## EPITECH PROJECT, 2020
## duostumper
## File description:
## Makefile
##

SRC			=		src/project/duo.c			\
					src/project/display/byte_display.c		\
					src/project/utilities/count_lr.c			\
					src/project/utilities/append.c			\
					src/project/utilities/smart_free.c	\
					src/project/display/line_display.c	\
					src/parsing/arg_parsing.c		\

MAIN_SRC	=		src/main.c					\

TEST_SRC	=		tests/tests_byte_display.c		\
				tests/tests_count_lr.c			\
				tests/tests_append.c			\
				tests/tests_line_display.c		\

OBJ			=		$(SRC:.c=.o)

MAIN_OBJ	=		$(MAIN_SRC:.c=.o)

TEST_OBJ	=		$(TEST_SRC:.c=.o)

COVERAGE	=		$(SRC:.c=.gcda)				\
					$(SRC:.c=.gcno)				\
					$(MAIN_SRC:.c=.gcno)		\
					$(MAIN_SRC:.c=.gcda)		\
					$(TEST_SRC:.c=.gcda)		\
					$(TEST_SRC:.c=.gcno)		\

CFLAGS		=		-I./include/ -Wall -Wextra -Werror

LFLAGS		=		-L./lib/ -lmy

TEST_LFLAGS	=		-lcriterion

TARGET		=		head

TARGET_TEST	=		yoshida

#-------------------------------------------------------------------------------

all:	$(TARGET)

$(TARGET): build_lib build

build_lib:
	@cd ./lib/libmy/ && $(MAKE) --silent
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
	@cd lib/libmy/ && $(MAKE) --silent clean

fclean_lib:
	@cd lib/libmy/ && $(MAKE) --silent fclean
	@rm -f lib/libmy.a

clean: clean_lib
	@rm -f $(OBJ) $(TEST_OBJ) $(MAIN_OBJ) $(COVERAGE)
	@printf "[\e[1;31mRemoved\e[0m] % 42s\n" $(OBJ) | tr ' ' '.'
	@printf "[\e[1;31mRemoved\e[0m] % 42s\n" $(TEST_OBJ) | tr ' ' '.'
	@printf "[\e[1;31mRemoved\e[0m] % 42s\n" $(MAIN_OBJ) | tr ' ' '.'
	@printf "[\e[1;31mRemoved\e[0m] % 42s\n" $(COVERAGE) | tr ' ' '.'
	@printf "\e[1;32mFinished removing objects\e[0m\n"

fclean: fclean_lib clean
	@rm -f $(TARGET) $(TARGET_TEST)
	@printf "[\e[1;31mRemoved\e[0m] % 42s\n" $(TARGET) | tr ' ' '.'
	@printf "[\e[1;31mRemoved\e[0m] % 42s\n" $(TARGET_TEST) | tr ' ' '.'
	@printf "\e[1;32mFinished removing linked binaries\e[0m\n"

re:	fclean all

tests_run: CFLAGS += --coverage
tests_run: build_lib $(OBJ) $(TEST_OBJ)
	@printf "\e[1;32mFinished compiling sources\e[0m\n"
	@$(CC) $(CFLAGS) $(OBJ) $(TEST_OBJ) -o $(TARGET_TEST) $(LFLAGS) $(TEST_LFLAGS)
	@printf "[\e[1;33mLinked\e[0m] % 43s\n" $(OBJ) | tr ' ' '.'
	@printf "[\e[1;33mLinked\e[0m] % 43s\n" $(TEST_OBJ) | tr ' ' '.'
	@printf "\e[1;32mLaunching tests...\e[0m]\n"
	@./$(TARGET_TEST)
	@gcovr --exclude tests/

re_tests: fclean tests_run

valgrind: all
	@valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

.PHONY:	re fclean clean fclean_lib clean_lib build build_lib all tests_run re_tests
