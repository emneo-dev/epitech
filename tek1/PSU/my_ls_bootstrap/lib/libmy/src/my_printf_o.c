/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Flag %o for my_printf
*/

#include <my.h>
#include <stdarg.h>

static void put_nbr_base_o(int nb, char *base, int *it)
{
    (*it)++;
    if (nb >= my_strlen(base))
        put_nbr_base_o(nb / my_strlen(base), base, it);
    my_putchar(base[nb % my_strlen(base)]);
}

int my_printf_o(va_list *aq)
{
    int tmp = va_arg(*aq, int);
    int bw = 0;
    put_nbr_base_o(tmp, "01234567", &bw);
    return (bw);
}
