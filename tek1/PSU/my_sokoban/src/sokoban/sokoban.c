/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** sokoban
*/

#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include "sokoban.h"

int sokoban(int argc, char **argv)
{
    int ret;

    if (argc != 2)
        return (84);
    if (!(my_strcmp(argv[1], "-h")))
        return (helper());
    o_link_t *map = load_map(argv[1]);
    if (map == NULL)
        return (84);
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    do {
        ret = main_loop(map);
        refresh();
    } while (ret);
    display_map(map);
    endwin();
    return (0);
}