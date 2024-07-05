/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** movement_handler
*/

#include <stdio.h>
#include "movement/structs.h"

static const float speed = 0.5;

int vertical_handler(map_t *map, sfClock *clock)
{
    float fact = sfClock_getElapsedTime(clock).microseconds / 500;
    float move = fact * speed;

    if (sfKeyboard_isKeyPressed(sfKeyDown) &&
        map->player->pos.y < map->pos.y + map->size.y - move - 40)
        map->player->pos.y += move;
    else if (sfKeyboard_isKeyPressed(sfKeyUp) &&
        map->player->pos.y > map->pos.y + move)
        map->player->pos.y -= move;
    return (0);
}

int horizontal_handler(map_t *map, sfClock *clock)
{
    float fact = sfClock_getElapsedTime(clock).microseconds / 500;
    float move = fact * speed;

    if (sfKeyboard_isKeyPressed(sfKeyLeft) &&
        map->player->pos.x > map->pos.x + move)
        map->player->pos.x -= move;
    else if (sfKeyboard_isKeyPressed(sfKeyRight) &&
        map->player->pos.x < map->pos.x + map->size.x - move - 40)
        map->player->pos.x += move;
    return (0);
}