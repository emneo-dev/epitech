/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** event_handler
*/

#include <ncurses.h>
#include "sokoban.h"

int event_handler(o_link_t *map)
{
    display_map(map);
    int ch = getch();
    switch (ch) {
        case 32:
            return (0);
        case KEY_UP:
            move_up(map);
            break;
        case KEY_DOWN:
            move_down(map);
            break;
        case KEY_LEFT:
            move_left(map);
            break;
        case KEY_RIGHT:
            move_right(map);
            break;
    }
    if (is_won(map))
        return (0);
    return (1);
}