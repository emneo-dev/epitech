##
## EPITECH PROJECT, 2019
## BSQ
## File description:
## The Makefile for BSQ
##

CC		=	gcc

SRC 	=	src/screensaver.c	\
		src/helper.c 	\
		src/anim_desc.c 	\
		src/scr1.c 	\
		src/scr2.c 	\
		src/scr3.c 	\
		src/put_str.c 	\
		src/my_strcmp.c \

TEST_SRC	=	tests/test_screensaver.c	\

OBJ 	=	$(SRC:.c=.o)

MAIN_SRC	=	src/main.c 	\

MAIN_OBJ	=	$(MAIN_SRC:.c=.o)

TEST_OBJ	=	$(TEST_SRC:.c=.o)

CFLAGS	=	-I./include -Wall -Wextra -pedantic -fno-builtin -Werror

TEST_CFLAGS	=	-lcriterion

LDFLAGS	=	-L./lib -lseal -lcsfml-graphics -lcsfml-system

TARGET	=	my_screensaver

TARGET_TEST	=	unit_tests

all:	$(TARGET)

$(TARGET):
	@cd ./lib/seal/ && make re
	@cp ./lib/seal/libseal.a ./lib/libseal.a
	@cp ./lib/seal/include/seal.h ./include/seal.h
	@$(MAKE) build

build: $(OBJ) $(MAIN_OBJ)
	@printf "\e[1;32mFinished compiling sources\e[0m\n"
	@gcc $(CFLAGS) $(OBJ) $(MAIN_OBJ) -o $(TARGET) $(LDFLAGS)
	@printf "[\e[1;33mLinked\e[0m] % 33s\n" $(OBJ) | tr ' ' '.'
	@printf "\e[1;32mLinked all object files\e[0m\n"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "[\e[1;34mCompiled\e[0m] % 31s\n" $< | tr ' ' '.'

clean:
	@rm -f $(OBJ) $(TEST_OBJ) $(MAIN_OBJ) *.gcda *.gcno
	@printf "[\e[1;31mRemoved\e[0m] % 32s\n" $(OBJ) $(TEST_OBJ) $(MAIN_OBJ) | tr ' ' '.'
	@printf "\e[1;32mFinished removing objects\e[0m\n"

test_build: $(OBJ) $(TEST_OBJ)
	@printf "\e[1;32mFinished compiling sources\e[0m\n"

tests_run: test_build
	@$(CC) $(CFLAGS) $(TEST_CFLAGS) $(OBJ) $(TEST_OBJ) -o $(TARGET_TEST) $(LDFLAGS) --coverage
	@printf "\e[1;32mLaunching tests...\e[0m\n"
	@./unit_tests

fclean: clean
	@rm -f $(TARGET) $(TARGET_TEST)
	@printf "[\e[1;31mRemoved\e[0m] % 32s\n" $(TARGET) | tr ' ' '.'
	@printf "\e[1;32mFinished removing linked binaries\e[0m\n"

re:	fclean all

re_tests: re tests_run
