/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Flag %o for my_printf
*/

#include <my.h>
#include <stdarg.h>

static void put_nbr_base_xl(int nb, char *base, int *it)
{
    (*it)++;
    if (nb >= my_strlen(base))
        put_nbr_base_xl(nb / my_strlen(base), base, it);
    my_putchar(base[nb % my_strlen(base)]);
}

int my_printf_xl(va_list *aq)
{
    int tmp = va_arg(*aq, int);
    int bw = 0;
    put_nbr_base_xl(tmp, "0123456789abcdef", &bw);
    return (bw);
}
