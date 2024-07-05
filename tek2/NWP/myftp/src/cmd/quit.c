/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** quit
*/

#include <string.h>

#include "ftp.h"

int exec_cmd_quit(char **cmd, server_t *srv, client_t *client)
{
    const char to_send[] = "221 Goodbye\r\n";

    UNUSED(cmd);
    smart_write(client->sockfd, to_send, strlen(to_send));
    FD_CLR(client->sockfd, srv->my_set);
    destroy_client(client);
    return 0;
}