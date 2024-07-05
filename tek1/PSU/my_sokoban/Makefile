##
## EPITECH PROJECT, 2019
## my_sokoban
## File description:
## The Makefile for my_sokoban
##

CC		=	gcc

SRC 	=	src/sokoban/sokoban.c				\
			src/sokoban/helper.c 				\
			src/use_function/my_strlen.c 		\
			src/use_function/put_str.c 			\
			src/use_function/my_strcmp.c 		\
			src/sokoban/load_map.c 				\
			src/sokoban/main_loop.c 			\
			src/sokoban/event_handler.c 		\
			src/sokoban/display_map.c 			\
			src/sokoban/movements/move_down.c 	\
			src/sokoban/movements/move_up.c 	\
			src/sokoban/movements/move_left.c 	\
			src/sokoban/movements/move_right.c 	\
			src/sokoban/movements/get_dest.c 	\
			src/sokoban/get_player_location.c 	\
			src/sokoban/get_player_node.c 		\
			src/sokoban/is_won.c				\

#TEST_SRC	=	tests/test_get_number.c	\

OBJ 	=	$(SRC:.c=.o)

MAIN_SRC	=	src/main.c 	\

MAIN_OBJ	=	$(MAIN_SRC:.c=.o)

#TEST_OBJ	=	$(TEST_SRC:.c=.o)

CFLAGS	=	-I./include -Wall -Wextra -Werror --coverage

#TEST_CFLAGS	=	-lcriterion

LDFLAGS	=	-lncurses

TARGET	=	my_sokoban

#TARGET_TEST	=	unit_tests

COVERAGE        =       $(SRC:.c=.gcda)         \
                        $(MAIN_SRC:.c=.gcda)    \
                        $(SRC:.c=.gcno)         \
                        $(MAIN_SRC:.c=.gcno)    \

all:	$(TARGET)

$(TARGET): $(OBJ) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MAIN_OBJ) -o $(TARGET) $(LDFLAGS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TEST_OBJ) $(MAIN_OBJ) $(COVERAGE)

test_build:
	$(MAKE) $(OBJ)
	$(MAKE) $(TEST_OBJ)

tests_run: test_build
	$(CC) $(CFLAGS) $(TEST_CFLAGS) $(OBJ) $(TEST_OBJ) -o $(TARGET_TEST) $(LDFLAGS)
	./unit_tests

fclean: clean
	rm -f $(TARGET) $(TARGET_TEST)

re:	fclean all

re_tests: re tests_run