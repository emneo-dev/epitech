/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** client
*/

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "ftp.h"

static const char ready_msg[] = "220 Service ready for new user\r\n";

static size_t find_empty_index(const client_t clients[MAX_CLIENTS])
{
    for (size_t i = 0; i < MAX_CLIENTS; ++i)
        if (!clients[i].is_used)
            return i;
    return -1;
}

// Returns the index to the newly accepted client
int accept_client(client_t clients[MAX_CLIENTS], int srv_sock,
    const char *home_path)
{
    const size_t cli_idx = find_empty_index(clients);
    socklen_t addr_size = sizeof(clients->addr);

    if (cli_idx == (size_t)-1) {
        fprintf(stderr, "Could not accept new client:\nToo many clients\n");
        return -1;
    }
    clients[cli_idx].sockfd = accept(srv_sock,
        (struct sockaddr *)&clients[cli_idx].addr, &addr_size);
    if (clients[cli_idx].sockfd == -1) {
        fprintf(stderr, "Could not accept new client:\n%s\n", strerror(errno));
        return -1;
    }
    clients[cli_idx].is_used = true;
    clients[cli_idx].conn_status = NOT_CONNECTED;
    clients[cli_idx].username = NULL;
    strcpy(clients[cli_idx].current_path, home_path);
    printf("%s - Client connected\n", get_client_string(&clients[cli_idx]));
    smart_write(clients[cli_idx].sockfd, ready_msg, strlen(ready_msg));
    return cli_idx;
}

void destroy_client(client_t *client)
{
    close(client->sockfd);
    if (client->username) {
        free(client->username);
        client->username = NULL;
    }
    client->is_used = false;
    printf("%s - Client disconnected\n", get_client_string(client));
}

int get_client_index(int fd, const client_t clients[MAX_CLIENTS])
{
    for (size_t i = 0; i < MAX_CLIENTS; ++i)
        if (clients[i].sockfd == fd && clients[i].is_used)
            return i;
    return -1;
}