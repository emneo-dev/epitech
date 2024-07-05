##
## EPITECH PROJECT, 2019
## MUL_my_rpg
## File description:
## Makefile for the my_rpg project
##

SHELL	=	bash

SRC_TALK	=	src/project/talk/init/init_talk.c							\
				src/project/talk/init/init_persons.c						\
				src/project/talk/init/init_font.c							\
				src/project/talk/init/init_nodes.c							\
				src/project/talk/destroy/destroy_talk.c						\
				src/project/talk/destroy/destroy_node.c						\
				src/project/talk/display/display_no_options.c				\
				src/project/talk/display/display_talk_node.c				\
				src/project/talk/display/display_talk_text.c				\
				src/project/talk/display/launch_talk.c						\
				src/project/talk/display/display_left_option.c				\
				src/project/talk/display/display_one_option.c				\
				src/project/talk/display/display_two_options.c				\
				src/project/talk/display/display_right_option.c				\
				src/project/talk/add_new_nodes.c							\

SRC_MENU	=	src/project/menu/menu.c										\
				src/project/menu/create_object.c							\
				src/project/menu/button_menu.c								\
				src/project/menu/button_click.c								\

SRC_MOV		=	src/project/movement/add_event_node.c						\
				src/project/movement/init/init_map.c						\
				src/project/movement/init/init_player.c						\
				src/project/movement/display/display_map.c					\
				src/project/movement/display/movement_handler.c				\
				src/project/movement/display/event_handler.c				\
				src/project/movement/cg_move_rect.c							\
				src/project/movement/cg_check_clock.c						\

SRC_INV 	= 	src/project/inventory/initialize_inventory.c 				\
				src/project/inventory/display_inventory.c					\

SRC_UTILITY	=	src/project/utility/my_puterr.c								\
				src/project/utility/my_putwarn.c							\
				src/project/utility/create_text.c							\

SRC_BASE	=	src/project/base/event_handler.c							\
				src/project/base/init_window.c								\
				src/project/base/init.c										\

SRC 	=	src/project/rpg.c												\
			$(SRC_BASE)														\
			$(SRC_UTILITY)													\
			$(SRC_TALK)														\
			$(SRC_MOV)														\
      		$(SRC_INV)                              						\
			$(SRC_MENU)														\

OBJ 	=	$(SRC:.c=.o)

MAIN_SRC	=	src/main.c 	\

MAIN_OBJ	=	$(MAIN_SRC:.c=.o)

CFLAGS	=	-I./include -Wall -Wextra -Werror

LFLAGS	=	-L./lib -lmy -lcsfml-graphics -lcsfml-system -lcsfml-window -lm

TARGET	=	rpg

#-------------------------------------------------------------------------------

all:	$(TARGET) ## Build the main binary with libs

$(TARGET) : build_lib build

build_lib: ## Compile the libs
	@$(MAKE) -C ./lib/libmy/ --silent
	@cp ./lib/libmy/libmy.a ./lib/libmy.a
	@cp ./lib/libmy/include/my.h ./include/my.h

%.o: %.c ## Compile the objects
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "[\e[1;34mCompiled\e[0m] % 41s\n" $@ | tr ' ' '.'

build: $(OBJ) $(MAIN_OBJ) ## Build the main binary
	@printf "\e[1;32mFinished compiling sources\e[0m\n"
	@$(CC) $(OBJ) $(MAIN_OBJ) -o $(TARGET) $(LFLAGS)
	@printf "\e[1;32mLinked all object files\e[0m\n"

clean_lib: ## Clean the libs
	@$(MAKE) -C ./lib/libmy/ --silent clean

fclean_lib: ## Force clean the libs
	@$(MAKE) -C ./lib/libmy/ --silent fclean
	@rm -f lib/libmy.a

clean: clean_lib ## Clean the project
	@rm -f $(OBJ) $(MAIN_OBJ)
	@printf "\e[1;32mFinished removing objects\e[0m\n"

fclean: fclean_lib clean ## Force clean the project
	@rm -f $(TARGET)
	@printf "\e[1;32mFinished removing linked binaries\e[0m\n"

re:	fclean all ## Force clean then compile

debug: CFLAGS += -g3
debug: re

valgrind: debug ## Launch valgrind
	@valgrind --leak-check=full --suppressions=./suppressions.valgrind ./$(TARGET)

help: ## Help for the Makefile
	@cat $(MAKEFILE_LIST) | sed -En 's/^([a-zA-Z_-]+)\s*:.*##\s?(.*)/\1 "\2"/p' | xargs printf "\033[36m%-30s\033[0m %s\n"

.PHONY:	re fclean clean fclean_lib clean_lib build build_lib all help valgrind