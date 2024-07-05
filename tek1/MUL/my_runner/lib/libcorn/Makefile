##
## EPITECH PROJECT, 2018
## libcorn
## File description:
## Makefile
##

SRC		=	src/corn_apply_gravity.c \
			src/corn_check_clock.c \
			src/corn_create_text.c \
			src/corn_move_rect.c \
			src/corn_load_sound.c \
			src/corn_load_sprite_from_file.c \

OBJ		=	$(SRC:.c=.o)

CFLAGS 	=	-Wall -Wextra -I./include/

TARGET	=	libcorn.a

PURPLE	=	\033[1;35m
GREEN	=	\033[1;92m
YELLOW	=	\033[1;33m
NORMAL	=	\033[0;39m

all:	$(TARGET)

goodbye:
	@echo -ne "\033[1;5;34m"
	@echo -e " ___   ___  ___  ___  ___       ___"
	@echo -e "/   | |   ||   ||   \|   / \ / |    "
	@echo -e "|   __|   ||   ||   ||---\  |  |--  "
	@echo -e "|___/ |___||___||___/|___/  |  |___$(NORMAL)"

build_text:
	@echo -e "$(PURPLE)Building libcorn....$(PURPLE)"

$(TARGET): build_text $(OBJ)
	@echo -e "$(YELLOW)Linking libcorn....$(YELLOW)"
	ar rc $(TARGET) $(OBJ)
	@echo -e "$(GREEN)Lib successfully created !$(NORMAL)"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)
	rm -f ../$(TARGET)
	@make --silent goodbye

re: clean all

.PHONY: all re clean fclean
