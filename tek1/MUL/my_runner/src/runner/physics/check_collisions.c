/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019 [WSL: Debian]
** File description:
** check_collisions
*/

#include "my_runner.h"

int check_collisions(game_object_t *objects)
{
    map_t *current = objects->map;

    for (; current; current = current->next) {
        if (is_sprite_colliding(current->top, objects->player->sprite))
            return (1);
        else if (is_sprite_colliding(current->bottom, objects->player->sprite))
            return (1);
    }
    return (0);
}