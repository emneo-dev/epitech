/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Handle the % flag for my_printf
*/

#include <stdarg.h>
#include <unistd.h>

int my_printf_perc(va_list *aq)
{
    aq = aq;
    write(1, "%", 1);
    return (1);
}

