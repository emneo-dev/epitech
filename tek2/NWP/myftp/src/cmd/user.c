/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** user
*/

#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#include "ftp.h"

static const char to_send_connected[] = "530 Can't change to another user.\r\n";

static const char to_send_succ[] = "331 Please specify the password.\r\n";

static void change_username(const char *username, client_t *client)
{
    if (client->username) {
        free(client->username);
        client->username = NULL;
    }
    if (username)
        client->username = strdup(username);
}

int exec_cmd_user(char **cmd, server_t *srv, client_t *client)
{
    if (client->conn_status == CONNECTED) {
        smart_write(client->sockfd, to_send_connected,
            strlen(to_send_connected));
        return 0;
    }
    UNUSED(srv);
    client->conn_status = (cmd[1] == NULL) ? NOT_CONNECTED : USER_CONNECTED;
    change_username(cmd[1], client);
    smart_write(client->sockfd, to_send_succ, strlen(to_send_succ));
    return 0;
}