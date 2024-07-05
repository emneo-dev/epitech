/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** unknown
*/

#include <stdio.h>
#include <string.h>

#include "ftp.h"

static const char to_send_unk[] = "500 Unknown command.\r\n";

int exec_cmd_unknown(char **cmd, server_t *srv, client_t *client)
{
    if (client->conn_status != CONNECTED)
        return send_not_connected(client);
    UNUSED(srv);
    fprintf(stderr, "%s - Could not execute command with suffix %s\n",
        get_client_string(client), cmd[0]);
    smart_write(client->sockfd, to_send_unk, strlen(to_send_unk));
    return 0;
}