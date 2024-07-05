/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Handle %c flag of my_printf
*/

#include <stdarg.h>
#include <my.h>
#include <stdio.h>

static void put_nbr_c(int nb, int *it)
{
    (*it)++;
    if (nb >= 10)
        put_nbr_c(nb / 10, it);
    my_putchar((nb % 10) + 48);
}

int my_printf_c(va_list *aq)
{
    int nb = va_arg(*aq, int);
    int bw = 0;
    int ret = nb % 255;
    put_nbr_c(ret, &bw);
    return (bw);
}
