/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Flag %p for my_printf
*/

#include <my.h>
#include <stdarg.h>

static void put_nbr_base_p(long long int nb, char *base, int *it)
{
    (*it)++;
    if (nb >= my_strlen(base))
        put_nbr_base_p(nb / my_strlen(base), base, it);
    my_putchar(base[nb % my_strlen(base)]);
}

int my_printf_p(va_list *aq)
{
    void *tmp = va_arg(*aq, void *);
    long long int ret = (long long int) (tmp);
    my_putstr("0x");
    int bw = 2;
    put_nbr_base_p(ret, "0123456789abcdef", &bw);
    return (bw);
}
