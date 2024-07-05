##
## EPITECH PROJECT, 2021
## B-CPP-300-TLS-3-1-CPPD01-alexandre.flion
## File description:
## Makefile
##

SRC		:=	main.c		\
			menger.c	\

CFLAGS	:=	-std=gnu11 -Wall -Wextra

LFLAGS	:=	-lm

CC		:=	gcc

OBJ		:=	$(patsubst %.c,%.o,$(SRC))

TARGET	:=	menger

all: $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(LFLAGS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all