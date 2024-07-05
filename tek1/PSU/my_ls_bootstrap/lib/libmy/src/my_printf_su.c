/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** printf S flag
*/

#include <my.h>
#include <stdarg.h>

int my_printf_su(va_list *aq)
{
    char *tmp = va_arg(*aq, char *);
    my_showstr(tmp);
    return (my_strlen(tmp));
}
