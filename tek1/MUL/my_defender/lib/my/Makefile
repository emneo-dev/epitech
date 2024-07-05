##
## EPITECH PROJECT, 2020
## MUL_my_defender_2019
## File description:
## Makefile
##

SRC		=		src/my_getnbr.c												\
				src/my_put_nbr.c											\
				src/my_putstr.c												\
				src/my_revstr.c												\
				src/my_strcat.c												\
				src/my_strcmp.c												\
				src/my_strcpy.c												\
				src/my_strdup.c												\
				src/my_strlen.c												\
				src/my_strlowcase.c											\
				src/my_strncat.c											\
				src/my_strncmp.c											\
				src/my_strncpy.c											\
				src/my_strstr.c												\
				src/my_strupcase.c											\
				src/my_putchar.c											\
				src/my_itoa.c												\
				src/my_append.c												\

OBJ			=		$(SRC:.c=.o)

CFLAGS		=		-I./include/ -Wall -Wextra -pedantic

TARGET		=		libmy.a

#-------------------------------------------------------------------------------

all:	$(TARGET)

$(TARGET): build

build: $(OBJ)
	ar rc $(TARGET) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re:	fclean all

.PHONY:	re fclean clean build all
