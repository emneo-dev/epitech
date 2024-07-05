/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Return the sum of the given args
*/

#include <stdarg.h>
#include <my.h>

int sum_stdarg(int i, int nb, ...)
{
    va_list aq;

    va_start(aq, nb);
    int ret = 0;
    for (int z = 0; z < nb; z++) {
        if (i)
            ret += my_strlen(va_arg(aq, char *));
        else
            ret += va_arg(aq, int);
    }
    return (ret);
}
