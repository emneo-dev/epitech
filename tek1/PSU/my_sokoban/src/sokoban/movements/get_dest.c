/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019 [WSL: Debian]
** File description:
** get_dest
*/

#include <stdlib.h>
#include "sokoban.h"

static int vec_eq(vector2d_t a, vector2d_t b) {
    if (a.x == b.x && a.y == b.y)
        return (1);
    return (0);
}

o_link_t *get_dest(vector2d_t pos, o_link_t *map)
{
    o_link_t *ret = NULL;
    for (; map != NULL; map = map->next) {
        if (ret == NULL && vec_eq(pos, map->position))
            ret = map;
        else if (ret != NULL)
            if (ret->priority == 0 && vec_eq(pos, map->position)
            && map->priority == 1)
                return (map);
    }
    return (ret);
}