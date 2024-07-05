/*
** EPITECH PROJECT, 2019
** CPool_finalstumper_2019
** File description:
** Entry file for the finalstumper project
*/

#include <rush3.h>
#include <my.h>

static int print_multiple_rush(int *length);

int rush3(char *buff)
{
    int *length = get_length(buff);
    int ex = get_ex(buff);
    if (ex == 6)
        return (print_multiple_rush(length));
    if (ex == 84)
        return (84);
    my_putstr("[rush1-");
    my_put_nbr(ex);
    my_putstr("] ");
    my_put_nbr(length[0]);
    my_putchar(' ');
    my_put_nbr(length[1]);
    my_putchar('\n');
    return (0);
}

static int print_multiple_rush(int *length)
{
    for (int i = 3; i < 6; i++) {
        my_putstr("[rush1-");
        my_put_nbr(i);
        my_putstr("] ");
        my_put_nbr(length[0]);
        my_putchar(' ');
        my_put_nbr(length[1]);
        if (i < 5)
            my_putstr(" || ");
    }
    my_putchar('\n');
    return (0);
}
