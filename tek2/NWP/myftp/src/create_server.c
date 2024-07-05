/*
** EPITECH PROJECT, 2021
** my_ftp
** File description:
** create_server
*/

#include <stdio.h>
#include <netdb.h>
#include <stdint.h>

#include "ftp.h"

server_t create_server(uint16_t port, const char *home_path)
{
    server_t srv = {
        .port = port,
        .home_path = home_path,
        .sockfd = socket(AF_INET, SOCK_STREAM, getprotobyname("TCP")->p_proto),
        .err = NO_ERROR,
        .addr = {
            .sin_addr.s_addr = htonl(INADDR_ANY),
            .sin_family = AF_INET,
            .sin_port = htons(port)
        }
    };

    printf("Launching the server...\n");
    if (srv.sockfd == -1)
        srv.err = SOCK_CREATION_ERROR;
    if (!check_home_path(srv.home_path))
        srv.err = HOME_PATH_ERROR;
    bind_server_socket(&srv);
    listen(srv.sockfd, SOMAXCONN);
    return srv;
}