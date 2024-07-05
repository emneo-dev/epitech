/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Print whether or not the given integer is negative
*/

#include <my.h>

int my_isneg(int n)
{
    (n >= 0) ? my_putchar('P') : my_putchar('N');
    return (0);
}
