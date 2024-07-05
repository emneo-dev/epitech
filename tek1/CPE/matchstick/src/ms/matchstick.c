/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019 [WSL: Debian]
** File description:
** matchstick
*/

#include <stdlib.h>
#include "ms.h"

int matchstick(int ac, char **av)
{
    map_t *map = NULL;

    if (ac != 3)
        return (84);
    map = get_map(av[1], av[2]);
    if (!map)
        return (84);
    return (game_loop(map));
}