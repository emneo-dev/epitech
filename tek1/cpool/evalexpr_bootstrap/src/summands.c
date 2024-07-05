/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_bootstrap_2019
** File description:
** Returns the sum of the expression given as parameter
*/

#include <my.h>

int summands(char **str)
{
    int length = my_strlen(*str);
    char *init = *str;
    int result = 0;

    while (init - *str < length)
        result = number(str);
    return (result);
}
