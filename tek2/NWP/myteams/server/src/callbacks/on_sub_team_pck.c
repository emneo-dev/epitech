/*
** EPITECH PROJECT, 2021
** my_teams
** File description:
** on_sub_team_pck
*/

#include "server.h"
#include "callbacks.h"

error_t on_sub_team_pck(const struct pck_sub_team *pck, client_t *client)
{
    error_t err = {
        .error_code = 0
    };

    UNUSED(pck);
    UNUSED(client);
    return err;
}