/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019 [WSL: Debian]
** File description:
** destroy_map
*/

#include <stdlib.h>
#include "ms.h"

void destroy_map(map_t *map)
{
    free(map->match);
    free(map);
}