/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Flag %u for my_printf
*/

#include <my.h>
#include <stdarg.h>

static void put_nbr_base_u(unsigned int nb, char *base, int *it)
{
    (*it)++;
    if (nb >= (unsigned int) my_strlen(base))
        put_nbr_base_u(nb / (unsigned int) my_strlen(base), base, it);
    my_putchar(base[nb % (unsigned int) my_strlen(base)]);
}

int my_printf_u(va_list *aq)
{
    unsigned int tmp = va_arg(*aq, int);
    int bw = 0;
    put_nbr_base_u(tmp, "0123456789", &bw);
    return (bw);
}
