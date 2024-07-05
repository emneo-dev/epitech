/*
** EPITECH PROJECT, 2019
** my_popup
** File description:
** Popup with the ncurses lib
*/

#include <ncurses.h>

static int my_strlen(char *str)
{
    int i;
    for (i = 0; str[i]; ++i);
    return (i);
}

int main(int argc, char **argv)
{
    int col;
    int row;
    int ch = 0;

    if (argc != 2)
        return (84);
    initscr();
    noecho();
    curs_set(0);
    do {
        getmaxyx(stdscr,row,col);
        clear();
        mvprintw(row / 2, (col - my_strlen(argv[1])) / 2, "%s", argv[1]);
        refresh();
        ch = getch();
    } while (ch != 32);
    endwin();
    return (0);
}
