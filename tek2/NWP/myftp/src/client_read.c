/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** client_read
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "ftp.h"

static char *find_crlf(char *str)
{
    for (size_t i = 0; i < strlen(str); ++i)
        if (!strncmp("\r\n", &str[i], 2))
            return &str[i];
    return NULL;
}

static void resize_buffer(client_t *client, size_t len)
{
    client->buffer_size -= len;
    if (client->buffer_size == 1) {
        free(client->read_buffer);
        client->read_buffer = NULL;
        return;
    }
    memmove(client->read_buffer, &client->read_buffer[len],
        client->buffer_size);
    client->read_buffer[client->buffer_size] = '\0';
}

static char *my_read_line(client_t *client)
{
    char *line_feed = NULL;
    size_t len = 0;
    char *ret_value = NULL;

    if (!client->read_buffer)
        return NULL;
    line_feed = find_crlf(client->read_buffer);
    if (!line_feed)
        return NULL;
    len = line_feed - client->read_buffer;
    ret_value = calloc(sizeof(char), (len + 1));
    if (!ret_value)
        return NULL;
    strncpy(ret_value, client->read_buffer, len);
    resize_buffer(client, len + 2);
    return ret_value;
}

static int my_append(char **str, const char *to_append)
{
    size_t len_str = 0;
    const size_t len_to_append = strlen(to_append);

    if (*str)
        len_str = strlen(*str);
    *str = realloc(*str, len_str + len_to_append + 1);
    strcpy(*str + len_str, to_append);
    return len_str + len_to_append + 1;
}

int read_client(client_t *client, server_t *srv)
{
    char buffer[1025] = {0};
    char *tmp = NULL;

    if (!read(client->sockfd, buffer, 1024))
        return -1;
    client->buffer_size = my_append(&client->read_buffer, buffer);
    tmp = my_read_line(client);
    while (tmp) {
        exec_raw_cmd(tmp, srv, client);
        free(tmp);
        tmp = my_read_line(client);
    }
    return 0;
}