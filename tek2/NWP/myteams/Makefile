##
## EPITECH PROJECT, 2021
## my_teams
## File description:
## Makefile
##

ROOT_DIR		:=	$(realpath .)

CLIENT_DIR		:=	$(ROOT_DIR)/client/

SERVER_DIR		:=	$(ROOT_DIR)/server/

CLIENT_TARGET	:=	myteams_cli

SERVER_TARGET	:=	myteams_server

all:	## Compiles the project
	$(MAKE) -C $(CLIENT_DIR) all
	$(MAKE) -C $(SERVER_DIR) all
	$(MAKE) copy_bins

copy_bins:	## Adds links to the executables
	ln -sf $(CLIENT_DIR)/$(CLIENT_TARGET) $(ROOT_DIR)/$(CLIENT_TARGET)
	ln -sf $(SERVER_DIR)/$(SERVER_TARGET) $(ROOT_DIR)/$(SERVER_TARGET)

clean:	## Cleans the compiles binaries
	$(MAKE) -C $(CLIENT_DIR) clean
	$(MAKE) -C $(SERVER_DIR) clean

fclean:	## Cleans the compiled binaries and executables
	$(MAKE) -C $(CLIENT_DIR) fclean
	$(MAKE) -C $(SERVER_DIR) fclean
	$(MAKE) remove_bins

remove_bins:	## Removes the links to the executables
	rm -f $(ROOT_DIR)/$(CLIENT_TARGET)
	rm -f $(ROOT_DIR)/$(SERVER_TARGET)

re:	## Recompiles the projects
	$(MAKE) fclean
	$(MAKE) all

help:	## Help for the Makefile
	@cat $(MAKEFILE_LIST) | sed -En 's/^([a-zA-Z_-]+)\s*:.*##\s?(.*)/\1 "\2"/p' | xargs printf "\033[36m%-30s\033[0m %s\n"