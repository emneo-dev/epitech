##
## EPITECH PROJECT, 2019
## my_pushswap
## File description:
## The Makefile for my_pushswap
##

CC		=	gcc

SRC 	=	src/pushswap/pushswap.c	\
			src/use_function/swap_values.c 	\
			src/use_function/char_to_int_ll.c 	\
			src/use_function/push_a_to_b.c 	\
			src/pushswap/sa_pa_pb.c 	\
			src/use_function/is_sorted.c 	\

OBJ 	=	$(SRC:.c=.o)

COVERAGE 	= 	$(SRC:.c=.gcda) 	\
				$(MAIN_SRC:.c=.gcda) 	\
				$(TEST_SRC:.c=.gcda) 	\
				$(SRC:.c=.gcno) 	\
				$(MAIN_SRC:.c=.gcno) 	\
				$(TEST_SRC:.c=.gcno) 	\

MAIN_SRC	=	src/main.c 	\

MAIN_OBJ	=	$(MAIN_SRC:.c=.o)

CFLAGS	=	-I./include -Wall -Wextra -Werror --coverage

TARGET	=	push_swap 	\

TEST_SRC 	= 	tests/test_char_to_int_ll.c 	\
				tests/test_push_a_to_b.c 	\
				tests/test_sa_pa_pb.c 	\
				tests/test_is_sorted.c 	\

TEST_OBJ 	= 	$(TEST_SRC:.c=.o)

TEST_TARGET 	= 	unit_tests

LDFLAGS 	= 	-lcriterion

all:	$(TARGET)

$(TARGET): $(OBJ) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MAIN_OBJ) -o $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(MAIN_OBJ) $(TEST_OBJ) $(COVERAGE)

fclean: clean
	rm -f $(TARGET) $(TEST_TARGET)

re:	fclean all

tests_build: $(OBJ) $(TEST_OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) $(TEST_OBJ) -o $(TEST_TARGET)

tests_run: tests_build
	./$(TEST_TARGET)
	gcovr --exclude tests/

re_tests: fclean tests_run