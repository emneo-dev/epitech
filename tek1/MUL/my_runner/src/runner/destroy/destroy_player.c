/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019 [WSL: Debian]
** File description:
** destroy_player
*/

#include <stdlib.h>
#include "my_runner.h"

void destroy_player(player_t *player)
{
    sfClock_destroy(player->clock);
    sfSprite_destroy(player->sprite);
    sfTexture_destroy(player->texture);
    free(player);
}