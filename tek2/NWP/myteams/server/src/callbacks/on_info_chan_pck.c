/*
** EPITECH PROJECT, 2021
** my_teams
** File description:
** on_info_chan_pck
*/

#include "server.h"
#include "callbacks.h"

error_t on_info_chan_pck(const struct pck_info_chan *pck, client_t *client)
{
    error_t err = {
        .error_code = 0
    };

    UNUSED(pck);
    UNUSED(client);
    return err;
}