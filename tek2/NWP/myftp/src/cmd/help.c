/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** help
*/

#include <string.h>

#include "ftp.h"

static const char to_send_help[] = "214 FTP server by huntears, have fun\r\n";

int exec_cmd_help(char **cmd, server_t *srv, client_t *client)
{
    if (client->conn_status != CONNECTED)
        return send_not_connected(client);
    UNUSED(cmd);
    UNUSED(srv);
    smart_write(client->sockfd, to_send_help, strlen(to_send_help));
    return 0;
}