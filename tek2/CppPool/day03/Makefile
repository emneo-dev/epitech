##
## EPITECH PROJECT, 2021
## B-CPP-300-TLS-3-1-CPPD03-alexandre.flion
## File description:
## Makefile
##

SRC		:=	string_init.c		\
			string_destroy.c	\
			append.c			\
			assign.c			\
			at.c				\
			c_str.c				\
			clear.c				\
			compare.c			\
			copy.c				\
			empty.c				\
			find.c				\
			insert.c			\
			join.c				\
			print.c				\
			size.c				\
			split.c				\
			substr.c			\
			to_int.c			\
			my_str_split.c		\
			my_split_cpy.c		\

TEST_SRC	:=	tests/tests_copy.c	\
				tests/tests_split.c	\

CFLAGS	:=	-std=gnu11 -W -Wall -Wextra -g3

CC		:=	gcc

OBJ		:=	$(patsubst %.c,%.o,$(SRC))

TEST_OBJ		:=	$(patsubst %.c,%.o,$(TEST_SRC))

COVERAGE		:=	$(patsubst %.c,%.gcno,$(SRC))		\
					$(patsubst %.c,%.gcda,$(SRC))		\
					$(patsubst %.c,%.gcno,$(TEST_SRC))	\
					$(patsubst %.c,%.gcda,$(TEST_SRC))	\

TARGET	:=	libstring.a

DEBUG_TARGET	:=	a.out

TARGET_TEST		:=	unit_tests

TEST_LFLAGS		:=	-lcriterion

all: $(OBJ)
	ar rc $(TARGET) $(OBJ)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ) $(TEST_OBJ) $(COVERAGE)

fclean: clean
	rm -f $(TARGET) $(TARGET_TEST)

re: fclean all

debug: all
	$(CC) main.c -L. -lstring -g3

re_debug: fclean debug

re_tests: fclean tests_run

tests_run: CFLAGS += --coverage
tests_run: $(OBJ) $(TEST_OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(TEST_OBJ) -o $(TARGET_TEST) $(TEST_LFLAGS)
	./$(TARGET_TEST)
