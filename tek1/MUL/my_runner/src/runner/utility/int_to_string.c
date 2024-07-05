/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019 [WSL: Debian]
** File description:
** int_to_string
*/

#include "my.h"

char *int_to_string(long long int nb)
{
    char *str = NULL;
    int i = 0;

    str = malloc(sizeof(char) * 20);
    for (i = 0; nb > 0; i++, nb /= 10)
        str[i] = nb % 10 + '0';
    str[i] = '\0';
    my_revstr(str);
    return (str);
}