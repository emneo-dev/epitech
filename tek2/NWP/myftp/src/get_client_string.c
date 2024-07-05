/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** get_client_string
*/

#include <string.h>
#include <stdio.h>

#include "ftp.h"

char *get_client_string(const client_t *client)
{
    static char buffer[50];

    memset(buffer, 0, 50);
    snprintf(buffer, 49, "%s:%hu", inet_ntoa(client->addr.sin_addr),
        ntohs(client->addr.sin_port));
    return buffer;
}