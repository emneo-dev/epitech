/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** my_putwarn
*/

#include <unistd.h>
#include "my.h"

void my_putwarn(char *warn)
{
    write(2, "\033[93mWarning\033[0m: ", my_strlen("\033[93mWarning\033[0m: "));
    write(2, warn, my_strlen(warn));
}