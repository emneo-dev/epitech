/*
** EPITECH PROJECT, 2021
** my_teams
** File description:
** on_create_reply_pck
*/

#include "server.h"
#include "callbacks.h"

error_t on_create_reply_pck(const struct pck_create_reply *pck,
    client_t *client)
{
    error_t err = {
        .error_code = 0
    };

    UNUSED(pck);
    UNUSED(client);
    return err;
}