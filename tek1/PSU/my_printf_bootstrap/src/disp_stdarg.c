/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Print the given args
*/

#include <stdarg.h>
#include <my.h>
#include <unistd.h>

static void print_arg(char type_arg, va_list *aq)
{
    if (type_arg == 'c') {
        char tmp = va_arg(*aq, int);
        write(1, &tmp, 1);
    } else if (type_arg == 's') {
        char *tmp = va_arg(*aq, char *);
        my_putstr(tmp);
    } else {
        int tmp = va_arg(*aq, int);
        my_put_nbr(tmp);
    }
    write(1, "\n", 1);
    return;
}

int disp_stdarg(char *s, ...)
{
    va_list aq;
    
    va_start(aq, s);
    for (int i = 0; i < my_strlen(s); i++)
        print_arg(s[i], &aq);
    return (0);
}