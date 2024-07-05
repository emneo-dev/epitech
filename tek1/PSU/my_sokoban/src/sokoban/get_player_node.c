/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019 [WSL: Debian]
** File description:
** get_player_node
*/

#include "sokoban.h"

o_link_t *get_player_node(o_link_t *map)
{
    for (; map->display != 'P'; map = map->next);
    return (map);
}