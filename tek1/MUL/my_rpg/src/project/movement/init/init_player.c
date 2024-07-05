/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** init_player
*/

#include <stdlib.h>
#include "utility.h"
#include "movement/structs.h"

int init_player(player_t *player, char const *path, inventory_t *inventory)
{
    if (!path)
        return (my_puterr("Could not init player! (Missing path)\n") - 1);
    player->texture = sfTexture_createFromFile(path, NULL);
    if (!player->texture)
        return (
        my_puterr("Could not init player! (texture creation failure)\n") - 1);
    player->pos = (sfVector2f) {0, 0};
    player->clock = sfClock_create();
    player->rect = (sfIntRect) {0, 80, 40, 40};
    player->inventory = inventory;
    return (0);
}