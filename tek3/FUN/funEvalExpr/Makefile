##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

NAME = funEvalExpr

EXE = evalExpr-exe

BINARY_PATH := $(shell stack path --local-install-root)

all:
	stack build
	cp $(BINARY_PATH)/bin/$(EXE) ./$(NAME)

clean:
	stack clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
