/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** pwd
*/

#include <stdio.h>

#include "ftp.h"

int exec_cmd_pwd(char **cmd, server_t *srv, client_t *client)
{
    char buffer[PATH_MAX + 1024] = {0};
    size_t size = 0;

    if (client->conn_status != CONNECTED)
        return send_not_connected(client);
    UNUSED(cmd);
    UNUSED(srv);
    size = snprintf(buffer, PATH_MAX + 1023,
        "257 \"%s\" is the current directory\r\n", client->current_path);
    smart_write(client->sockfd, buffer, size);
    return 0;
}