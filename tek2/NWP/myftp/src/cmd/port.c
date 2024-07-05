/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** port
*/

#include "ftp.h"

int exec_cmd_port(char **cmd, server_t *srv, client_t *client)
{
    if (client->conn_status != CONNECTED)
        return send_not_connected(client);
    UNUSED(cmd);
    UNUSED(srv);
    UNUSED(client);
    return 0;
}