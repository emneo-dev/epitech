/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Output a given string to stdout
*/

#include <my.h>
#include <unistd.h>

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return (0);
}
