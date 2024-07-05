##
## EPITECH PROJECT, 2020
## PSU_my_ls_bootstrap_2019
## File description:
## Makefile
##

SRC 	=	src/main.c	\
			src/info_file.c 	\

OBJ 	=	$(SRC:.c=.o)

CFLAGS	=	-I./include -Wall -Wextra -Werror

LDFLAGS	=	-L./lib -lmy

TARGET	=	info_file

all:	$(TARGET)

$(TARGET): build_lib build

build_lib:
	cd lib/libmy/ && $(MAKE)
	cp lib/libmy/libmy.a lib/libmy.a
	cp lib/libmy/include/my.h include/my.h

build: $(OBJ) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) $(LDFLAGS)

clean:
	cd lib/libmy/ && $(MAKE) clean
	rm -f $(OBJ)

fclean: clean
	cd lib/libmy/ && $(MAKE) fclean
	rm -f $(TARGET)

re:	fclean all