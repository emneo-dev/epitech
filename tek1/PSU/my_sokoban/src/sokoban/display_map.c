/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** display_map
*/

#include <ncurses.h>
#include <stdlib.h>
#include "sokoban.h"

static vector2d_t get_highest(o_link_t *map)
{
    vector2d_t ret = {0, 0};
    for (; map != NULL; map = map->next) {
        ret.x = (ret.x < map->position.x) ? map->position.x : ret.x;
        ret.y = (ret.y < map->position.y) ? map->position.y : ret.y;
    }
    return (ret);
}

void display_map(o_link_t *map)
{
    vector2d_t high = get_highest(map);
    char *buff = malloc(sizeof(char) * (high.y + 1) * (high.x + 1));

    clear();
    for (int x = 0; x <= high.x; ++x)
        for (int y = 0; y <= high.y; ++y)
            *(buff + x + y * (high.x + 1)) = 0;
    for (; map != NULL; map = map->next)
        if ((map->priority == 0 && *(buff + map->position.x + map->position.y
            * (high.x + 1)) == 0) || map->priority)
            *(buff + map->position.x + map->position.y * (high.x + 1))
            = map->display;
    for (int y = 0; y <= high.y; ++y)
        for (int x = 0; x <= high.x; ++x)
            mvprintw(y, x, "%c", *(buff + x + y * (high.x + 1)));
    free(buff);
    return;
}