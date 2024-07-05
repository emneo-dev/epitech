/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019 [WSL: Debian]
** File description:
** destroy_map
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_runner.h"

void destroy_map(map_t *map)
{
    map_t *next = NULL;

    while (map) {
        sfSprite_destroy(map->bottom);
        sfSprite_destroy(map->top);
        sfTexture_destroy(map->bottom_tex);
        sfTexture_destroy(map->top_tex);
        next = map->next;
        free(map);
        map = next;
    }
}