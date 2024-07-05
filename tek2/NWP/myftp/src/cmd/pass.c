/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** pass
*/

#include <string.h>
#include <stdlib.h>

#include "ftp.h"

static const char to_send_user[] = "503 Login with USER first.\r\n";

static const char to_send_logged[] = "230 Already logged in.\r\n";

static const char to_send_ncor[] = "530 Login incorrect.\r\n";

static const char to_send_succ[] = "230 Login successful.\r\n";

int exec_cmd_pass(char **cmd, server_t *srv, client_t *client)
{
    if (client->conn_status == NOT_CONNECTED) {
        smart_write(client->sockfd, to_send_user, strlen(to_send_user));
        return 0;
    } else if (client->conn_status == CONNECTED) {
        smart_write(client->sockfd, to_send_logged, strlen(to_send_logged));
        return 0;
    }
    UNUSED(srv);
    if (client->username == NULL || strcmp("Anonymous", client->username)
        || cmd[1]) {
        smart_write(client->sockfd, to_send_ncor, strlen(to_send_ncor));
        if (client->username == NULL) {
            free(client->username);
            client->username = NULL;
        }
        client->conn_status = NOT_CONNECTED;
        return 0;
    }
    smart_write(client->sockfd, to_send_succ, strlen(to_send_succ));
    client->conn_status = CONNECTED;
    return 0;
}