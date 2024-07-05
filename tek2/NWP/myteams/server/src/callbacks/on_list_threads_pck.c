/*
** EPITECH PROJECT, 2021
** my_teams
** File description:
** on_list_threads_pck
*/

#include "server.h"
#include "callbacks.h"

error_t on_list_threads_pck(const struct pck_list_threads *pck, client_t *client)
{
    error_t err = {
        .error_code = 0
    };

    UNUSED(pck);
    UNUSED(client);
    return err;
}