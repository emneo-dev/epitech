/*
** EPITECH PROJECT, 2021
** my_ftp
** File description:
** launch_server_loop
*/

#include <sys/select.h>
#include <stddef.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

#include "ftp.h"

// This would so much better as a define to avoid dynamic
// sized arrays in the stack, which also avoids the memset
// used in launch_server_loop
const size_t MAX_CLIENTS = 512;

static int handle_select_errors(void)
{
    if (errno != EINTR)
        fprintf(stderr, "Select failed :\n%s\n", strerror(errno));
    return 84;
}

static void handle_input(server_t *srv, client_t clients[MAX_CLIENTS],
    fd_set *wk_set, fd_set *my_set)
{
    for (int i = 0; i < FD_SETSIZE; ++i)
        if (FD_ISSET(i, wk_set))
            handle_fd_input(srv, clients, my_set, i);
}

// http://bit.ly/select_so_utilisation
int launch_server_loop(server_t *srv)
{
    client_t clients[MAX_CLIENTS];
    fd_set my_set;
    fd_set wk_set;

    srv->my_set = &my_set;
    memset(clients, 0, sizeof(clients));
    FD_ZERO(&my_set);
    FD_SET(srv->sockfd, &my_set);
    while (1) {
        memcpy(&wk_set, &my_set, sizeof(my_set));
        if (select(FD_SETSIZE + 1, &wk_set, NULL, NULL, NULL) == -1)
            handle_select_errors();
        handle_input(srv, clients, &wk_set, &my_set);
    }
}