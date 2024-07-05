/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019 [WSL: Debian]
** File description:
** game_loop
*/

#include <stdio.h>
#include "my.h"
#include "ms.h"

int game_loop(map_t *map)
{
    display_map(map);
    while (1) {
        if (!entry_point(map))
            return (0);
        display_map(map);
        if (is_empty(map)) {
            my_putstr("You lost, too bad...\n");
            return (2);
        }
        ai(map);
        display_map(map);
        if (is_empty(map)) {
            my_putstr("I lost... snif... but I'll get you next time!!\n");
            return (1);
        }
    }
}