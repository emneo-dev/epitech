/*
** EPITECH PROJECT, 2020
** PSU_my_exec_2019 [WSL: Debian]
** File description:
** my_put_nbr
*/

#include "my_exec.h"

void my_put_nbr(int nb)
{
    if (nb >= 10)
        my_put_nbr(nb / 10);
    my_putchar(nb % 10 + '0');
}