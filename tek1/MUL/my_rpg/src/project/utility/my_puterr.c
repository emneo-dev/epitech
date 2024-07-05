/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** my_puterr
*/

#include <unistd.h>
#include "my.h"

int my_puterr(char *err)
{
    write(2, "\033[91mError\033[0m: ", my_strlen("\033[91mError\033[0m: "));
    write(2, err, my_strlen(err));
    return (0);
}