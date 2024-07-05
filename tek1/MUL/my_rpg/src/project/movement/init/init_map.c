/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** init_map
*/

#include <stdlib.h>
#include "utility.h"
#include "movement/structs.h"

int init_map(map_t *map, new_map_t *new_map, player_t *player)
{
    map->texture = sfTexture_createFromFile(new_map->map_path, NULL);
    if (!map->texture)
        return (
        my_puterr("Could not init map! (texture creation failed)\n") - 1);
    map->size = new_map->size;
    map->pos = new_map->position;
    map->start_pos = new_map->start_pos;
    map->evt = NULL;
    map->player = player;
    return (0);
}