/*
** EPITECH PROJECT, 2021
** my_ftp
** File description:
** launch_server
*/

#include <stdio.h>
#include <stdint.h>

#include "ftp.h"

int launch_server(uint16_t port, const char *home_path)
{
    server_t srv = create_server(port, home_path);

    if (srv.err != NO_ERROR)
        return 84;
    printf("Server launched and listening on %s:%hu\n",
        inet_ntoa(srv.addr.sin_addr), srv.port);
    launch_server_loop(&srv);
    return 0;
}