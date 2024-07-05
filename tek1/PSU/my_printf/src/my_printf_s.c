/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Flag %s support for my_printf
*/

#include <my.h>
#include <stdarg.h>

int my_printf_s(va_list *aq)
{
    char *tmp = va_arg(*aq, char *);
    my_putstr(tmp);
    return (my_strlen(tmp));
}
