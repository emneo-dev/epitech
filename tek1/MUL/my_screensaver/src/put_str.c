/*
** EPITECH PROJECT, 2019
** screensaver
** File description:
** List of the available animations
*/

#include <unistd.h>

static int get_len(char *str)
{
    int i;
    for (i = 0; str[i]; i++);
    return (i);
}

int put_str(char *str)
{
    write(1, str, get_len(str));
    return (get_len(str));
}