/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Flag %o for my_printf
*/

#include <my.h>
#include <stdarg.h>
#include <errno.h>

static void put_nbr_base_m(int nb, char *base, int *it)
{
    (*it)++;
    if (nb >= my_strlen(base))
        put_nbr_base_m(nb / my_strlen(base), base, it);
    my_putchar(base[nb % my_strlen(base)]);
}

int my_printf_m(va_list *aq)
{
    aq = aq;
    int bw = 0;
    put_nbr_base_m(errno, "0123456789", &bw);
    return (bw);
}
