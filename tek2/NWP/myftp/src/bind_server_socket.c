/*
** EPITECH PROJECT, 2021
** my_ftp
** File description:
** bind_server_socket
*/

#include <errno.h>
#include <string.h>
#include <stdio.h>

#include "ftp.h"

void bind_server_socket(server_t *srv)
{
    if (srv->err != NO_ERROR)
        return;
    setsockopt(srv->sockfd, SOL_SOCKET, SO_REUSEADDR, (int[1]){1}, sizeof(int));
    if (bind(srv->sockfd, (struct sockaddr *)&srv->addr, sizeof(srv->addr))
        == -1) {
        fprintf(stderr, "Could not bind server to port %hu, Error:\n"
            "%s\n", srv->port, strerror(errno));
        srv->err = BIND_ERROR;
    }
}