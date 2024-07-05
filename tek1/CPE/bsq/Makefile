##
## EPITECH PROJECT, 2019
## BSQ
## File description:
## The Makefile for BSQ
##

SRC 	=	src/load_file_to_mem.c	\
		src/get_number.c	\
		src/is_upper_side.c 	\
		src/is_left_side.c 	\
		src/my_set_value.c 	\
		src/loop_value.c 	\
		src/get_shortest.c 	\
		src/get_highest.c 	\
		src/display_bsq.c 	\
		src/convert_to_v2.c 	\
		src/is_in_square.c 	\

TEST_SRC	=	tests/test_get_number.c	\
			tests/test_load_file_to_mem.c 	\
			tests/test_is_upper_side.c 	\
			tests/test_is_left_side.c 	\
			tests/test_set_value.c 	\
			tests/test_loop_value.c \

OBJ 	=	$(SRC:.c=.o)

MAIN_SRC	=	src/bsq.c 	\

MAIN_OBJ	=	$(MAIN_SRC:.c=.o)

TEST_OBJ	=	$(TEST_SRC:.c=.o)

CFLAGS	=	-I./include -Wall -Wextra -pedantic -fno-builtin -Werror -g3

TEST_CFLAGS	=	-lcriterion

TARGET	=	bsq

TARGET_TEST	=	unit_tests

all:	$(TARGET)

$(TARGET): $(OBJ) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MAIN_OBJ) -o $(TARGET) $(LIB_FLAGS)

clean:
	rm -f $(OBJ) $(TEST_OBJ) $(MAIN_OBJ) *.gcda *.gcno

tests_run: $(OBJ) $(TEST_OBJ)
	$(CC) $(CFLAGS) $(TEST_CFLAGS) $(OBJ) $(TEST_OBJ) -o $(TARGET_TEST)
	./unit_tests

fclean: clean
	rm -f $(TARGET) $(TARGET_TEST)

re:	fclean all

re_tests: re tests_run
