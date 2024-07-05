/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019 [WSL: Debian]
** File description:
** is_empty
*/

#include "ms.h"

int is_empty(map_t *map)
{
    for (int i = 0; i < map->size; ++i)
        if (map->match[i])
            return (0);
    return (1);
}