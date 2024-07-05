/*
** EPITECH PROJECT, 2021
** nmobjdump
** File description:
** get_size_max_addr
*/

#include <objdump.h>

size_t get_size_max_addr(size_t i)
{
    size_t r = 0;

    while (i >>= 1)
        r++;
    return (r / 4 + 1 > 4) ? r / 4 + 1 : 4;
}