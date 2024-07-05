/*
** EPITECH PROJECT, 2021
** my_teams
** File description:
** on_list_replies_pck
*/

#include "server.h"
#include "callbacks.h"

error_t on_list_replies_pck(const struct pck_list_replies *pck,
    client_t *client)
{
    error_t err = {
        .error_code = 0
    };

    UNUSED(pck);
    UNUSED(client);
    return err;
}