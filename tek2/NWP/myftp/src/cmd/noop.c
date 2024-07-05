/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** noop
*/

#include <string.h>

#include "ftp.h"

// Good implementation smh
int exec_cmd_noop(char **cmd, server_t *srv, client_t *client)
{
    const char to_send[] = "200 Command okay.\r\n";

    if (client->conn_status != CONNECTED)
        return send_not_connected(client);
    UNUSED(cmd);
    UNUSED(srv);
    smart_write(client->sockfd, to_send, strlen(to_send));
    return 0;
}