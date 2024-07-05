##
## EPITECH PROJECT, 2020
## MUL_my_defender_2019
## File description:
## Makefile
##

SRC			=		src/cg_apply_gravity.c									\
					src/cg_check_clock.c									\
					src/cg_check_inbox.c									\
					src/cg_create_text.c									\
					src/cg_get_distance.c									\
					src/cg_load_sound.c										\
					src/cg_load_sprite_from_file.c							\
					src/cg_move_rect.c										\
					src/cg_vchange.c										\

OBJ			=		$(SRC:.c=.o)

CFLAGS		=		-I./include/ -Wall -Wextra -pedantic

TARGET		=		libcg.a

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
