##
## EPITECH PROJECT, 2020
## CPE_solostumper_1_2019
## File description:
## Makefile
##

SRC 	=	src/find_needle.c	\

MAIN_SRC 	=	src/main.c	\

TEST_SRC	=	tests/test_hidenp.c	\

OBJ 	=	$(SRC:.c=.o)

MAIN_OBJ	=	$(MAIN_SRC:.c=.o)

TEST_OBJ	=	$(TEST_SRC:.c=.o)

CFLAGS	=	-I./include/ -Wall -Wextra -pedantic -fno-builtin -Werror --coverage

LDFLAGS	=	-I./include/ -lcriterion

TARGET	=	hidenp

TEST_TARGET	=	unit_tests

all:	$(TARGET)

$(TARGET): build

build: $(OBJ) $(MAIN_OBJ)
	@echo "Such program"
	@echo "Much bad code"
	$(CC) $(CFLAGS) $(LDFLAGS) $(MAIN_OBJ) $(OBJ) -o $(TARGET)

clean:
	@echo "Time to clean this mess !"
	rm -f $(OBJ) $(MAIN_OBJ) $(TEST_OBJ)

fclean: clean
	@echo "owo don't erase me T_T"
	rm -f $(TARGET) $(TEST_TARGET)

tests_run: $(OBJ) $(TEST_OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(TEST_OBJ) $(OBJ) -o $(TEST_TARGET)
	./$(TEST_TARGET)
	gcovr --exclude tests/

re:	fclean all

.PHONY:	re fclean clean build all
