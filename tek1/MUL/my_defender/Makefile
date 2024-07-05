##
## EPITECH PROJECT, 2020
## MUL_my_defender_2019
## File description:
## Makefile
##

SRC_TOWER	=		src/game/tower/create_button.c							\
					src/game/tower/check_tower_click.c						\
					src/game/tower/attack.c									\
					src/game/tower/set_type/electric.c						\
					src/game/tower/set_type/bomb.c							\
					src/game/tower/set_type/arrow.c							\
					src/game/tower/set_type/frost.c							\
					src/game/tower/set_type/flame.c							\
					src/game/tower/set_type/none.c							\

SRC_MENU	=		src/game/build_menu/init.c								\
					src/game/build_menu/open.c								\
					src/game/build_menu/close.c								\
					src/game/build_menu/check_button_clicked.c				\
					src/menu/draw_menu.c									\
					src/menu/menu_creation.c								\
					src/menu/menu_loop.c									\

SRC_ENEMY	=		src/game/enemy/destroy.c								\
					src/game/enemy/follow_path.c							\
					src/game/enemy/init.c									\
					src/game/enemy/set_path.c								\
					src/game/enemy/is_in_range.c							\

SRC_PLAYER	=		src/game/player/init.c									\
					src/game/player/change_coin.c							\

SRC			=		src/core.c												\
					src/destroy_core.c										\
					src/destroy_menu.c										\
					src/game/draw_game.c									\
					src/game/game_loop.c									\
					src/game/event_handling.c								\
					$(SRC_TOWER)											\
					$(SRC_MENU)												\
					$(SRC_ENEMY)											\
					$(SRC_PLAYER)											\

MAIN_SRC	=		src/main.c					\

OBJ			=		$(SRC:.c=.o)

MAIN_OBJ	=		$(MAIN_SRC:.c=.o)

CFLAGS		=		-I./include/ -Wall -Wextra -pedantic

LFLAGS		=		-L./lib/ -lmy -lcg -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

TARGET		=		my_defender

#-------------------------------------------------------------------------------

all:	$(TARGET)

$(TARGET): build_lib build

build_lib:
	$(MAKE) -C lib/my/
	cp ./lib/my/libmy.a ./lib/libmy.a
	cp ./lib/my/include/my.h ./include/my.h
	$(MAKE) -C lib/cg/
	cp ./lib/cg/libcg.a ./lib/libcg.a
	cp ./lib/cg/include/cg.h ./include/cg.h

build: $(OBJ) $(MAIN_OBJ)
	$(CC) $(OBJ) $(MAIN_OBJ) -o $(TARGET) $(LFLAGS)

clean_lib:
	$(MAKE) -C lib/my/ clean
	$(MAKE) -C lib/cg/ clean

fclean_lib:
	$(MAKE) -C lib/my/ fclean
	$(MAKE) -C lib/cg/ fclean
	rm -f lib/libmy.a
	rm -f lib/libcg.a

clean: clean_lib
	rm -f $(OBJ) $(MAIN_OBJ)

fclean: fclean_lib clean
	rm -f $(TARGET)

re:	fclean all

debug: CFLAGS += -g3
debug: re

valgrind: debug
	valgrind --leak-check=full --suppressions=./suppressions.valgrind ./$(TARGET)

.PHONY:	re fclean clean fclean_lib clean_lib build build_lib all valgrind
