/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** init_lib
*/

#include <ncurses.h>
#include "sokoban.h"

int main_loop(o_link_t *map)
{
    return (event_handler(map));
}