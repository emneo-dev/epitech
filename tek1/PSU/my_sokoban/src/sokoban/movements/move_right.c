/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019 [WSL: Debian]
** File description:
** move_right
*/

#include "sokoban.h"

static int move_box(o_link_t *box, o_link_t *map)
{
    vector2d_t to_move = (vector2d_t) {box->position.x + 1, box->position.y};
    o_link_t *dest = get_dest(to_move, map);
    if (dest->display != 'X' && dest->display != '#') {
        box->position = to_move;
        return (1);
    }
    return (0);
}

int move_right(o_link_t *map)
{
    vector2d_t p_pos = get_player_location(map);
    o_link_t *player = get_player_node(map);
    vector2d_t to_move = (vector2d_t) {p_pos.x + 1, p_pos.y};
    o_link_t *dest = get_dest(to_move, map);
    int ret;

    if (dest->display != 'X' && dest->display != '#')
        player->position = to_move;
    else if (dest->display == 'X') {
        ret = move_box(dest, map);
        if (ret)
            player->position = to_move;
    }
    return (1);
}