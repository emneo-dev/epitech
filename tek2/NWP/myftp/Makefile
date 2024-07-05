##
## EPITECH PROJECT, 2021
## ftp
## File description:
## Makefile
##

SRC					:=	src/ftp.c											\
						src/print_help.c									\
						src/launch_server.c									\
						src/bind_server_socket.c							\
						src/create_server.c									\
						src/check_home_path.c								\
						src/smart_write.c 									\
						src/launch_server_loop.c							\
						src/client.c										\
						src/handle_cmd.c									\
						src/get_client_string.c								\
						src/handle_fd_input.c								\
						src/client_read.c									\
						src/cmd/send_not_connected.c						\
						src/cmd/noop.c										\
						src/cmd/cdup.c										\
						src/cmd/cwd.c										\
						src/cmd/dele.c										\
						src/cmd/help.c										\
						src/cmd/list.c										\
						src/cmd/pass.c										\
						src/cmd/pasv.c										\
						src/cmd/port.c										\
						src/cmd/pwd.c										\
						src/cmd/quit.c										\
						src/cmd/retr.c										\
						src/cmd/stor.c										\
						src/cmd/user.c										\
						src/cmd/unknown.c									\

OBJ 				:=	$(SRC:.c=.o)

CPPFLAGS			:=	-I./include/

TARGET				:=	myftp

CFLAGS				:=	-Wall -Wextra -pedantic -fno-builtin -g3

LDFLAGS				:=

#-------------------------------------------------------------------------------

all: $(TARGET) ## Build the main binaries

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $(TARGET)

clean: ## Clean the project
	rm -f $(OBJ)

fclean: clean ## Force clean the project
	rm -f $(TARGET)

re:	fclean ## Force clean then compile
	$(MAKE) all

help: ## Help for the Makefile
	@cat $(MAKEFILE_LIST) | sed -En 's/^([a-zA-Z_-]+)\s*:.*##\s?(.*)/\1 "\2"/p' | xargs printf "\033[36m%-30s\033[0m %s\n"

.PHONY:	re fclean clean build all tests_run re_tests help