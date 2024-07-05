/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** handle_fd_input
*/

#include "ftp.h"

static void handle_new_user(const server_t *srv, client_t clients[MAX_CLIENTS],
    fd_set *my_set)
{
    int cli_idx = accept_client(clients, srv->sockfd, srv->home_path);

    if (cli_idx == -1)
        return;
    FD_SET(clients[cli_idx].sockfd, my_set);
}

static void handle_user_input(server_t *srv,
    client_t clients[MAX_CLIENTS], fd_set *my_set, int fd)
{
    if (read_client(&clients[get_client_index(fd, clients)], srv) == -1) {
        destroy_client(&clients[get_client_index(fd, clients)]);
        FD_CLR(fd, my_set);
    }
}

void handle_fd_input(server_t *srv, client_t clients[MAX_CLIENTS],
    fd_set *my_set, int fd)
{
    if (fd == srv->sockfd)
        handle_new_user(srv, clients, my_set);
    else
        handle_user_input(srv, clients, my_set, fd);
}