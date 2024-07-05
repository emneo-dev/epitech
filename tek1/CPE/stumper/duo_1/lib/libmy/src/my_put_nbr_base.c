/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_put_nbr_base
*/

#include "my.h"

int my_put_nbr_base(int nb, char *base)
{
    if (nb >= my_strlen(base))
        put_nbr_base_xl(nb / my_strlen(base), base);
    my_putchar(base[nb % my_strlen(base)]);
    return (0);
}