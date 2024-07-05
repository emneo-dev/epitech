##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

NAME = imageCompressor

EXE = imageCompressor-exe

BINARY_PATH := $(shell stack path --local-install-root)

all:
	stack build $(NAME)
	cp $(BINARY_PATH)/bin/$(EXE) ./$(NAME)

clean:
	stack clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re