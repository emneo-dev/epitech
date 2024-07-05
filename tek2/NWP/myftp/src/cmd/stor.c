/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** stor
*/

#include "ftp.h"

int exec_cmd_stor(char **cmd, server_t *srv, client_t *client)
{
    if (client->conn_status != CONNECTED)
        return send_not_connected(client);
    UNUSED(cmd);
    UNUSED(srv);
    UNUSED(client);
    return 0;
}