/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019 [WSL: Debian]
** File description:
** is_won
*/

#include "my_runner.h"

int is_won(game_object_t *objects)
{
    map_t *current = objects->map;

    for (; current; current = current->next)
        if (sfSprite_getPosition(current->top).x > 300)
            return (0);
    objects->is_won = 1;
    return (1);
}