/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019 [WSL: Debian]
** File description:
** display_map
*/

#include <unistd.h>
#include "ms.h"

static void display_line(short size)
{
    size = size * 2 + 1;
    for (; size > 0; size--, write(1, "*", 1));
    write(1, "\n", 1);
}

void display_map(map_t *map)
{
    short z = 0;

    display_line(map->size);
    for (short i = 1; i <= map->size; i++) {
        write(1, "*", 1);
        for (z = 0; z < map->size - i; z++)
            write(1, " ", 1);
        for (z = 0; z < map->match[i - 1]; z++)
            write(1, "|", 1);
        for (z = 0; z < map->size - i + ((i - 1) * 2 + 1) - map->match[i - 1];
            z++)
            write(1, " ", 1);
        write(1, "*\n", 2);
    }
    display_line(map->size);
}