/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Check whether or not the given index is on the left side
*/

#include <bsq.h>

int is_left_side(map_t mem, long int index)
{
    if (index % (mem.columns + 1) == 0)
        return (1);
    return (0);
}
