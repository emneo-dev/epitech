/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** send_not_connected
*/

#include <string.h>

#include "ftp.h"

int send_not_connected(const client_t *client)
{
    const char to_send[] = "530 Please login with USER and PASS\r\n";

    smart_write(client->sockfd, to_send, strlen(to_send));
    return 0;
}