/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Handle %c flag of my_printf
*/

#include <stdarg.h>
#include <my.h>
#include <stdio.h>

int my_printf_c(va_list *aq)
{
    int nb = va_arg(*aq, int);
    my_putchar((char) nb);
    return (1);
}
