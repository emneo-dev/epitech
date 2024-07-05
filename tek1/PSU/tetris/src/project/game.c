/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** game
*/

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include "struct.h"
#include "prototype.h"

int game(args_t *args, tetr_t *tetr)
{
    free_struct(args, tetr);
    return (EXIT_SUCCESS);
}

// void write_text(const char *str, int x, int y)
// {
//     for (int i = 0; str[i]; i++)
//         mvaddch(y, x + i, str[i]);
// }

//     WINDOW *boite;
//     initscr();
//     boite= subwin(stdscr, 20, 10, 0, 0);
//     box(boite, ACS_VLINE, ACS_BLOCK); // ACS_VLINE et ACS_HLINE sont des constantes qui génèrent des bordures par défaut
//     write_text("*** *** *** *** * ***", 10 + 30, 2);
//     write_text(" *  *    *  * *   *  ", 10 + 30, 3);
//     write_text(" *  **   *  **  * ***", 10 + 30, 4);
//     write_text(" *  *    *  * * *   *", 10 + 30, 5);
//     write_text(" *  ***  *  * * * ***", 10 + 30, 6);
//     refresh();
//     getch();
//     endwin();
