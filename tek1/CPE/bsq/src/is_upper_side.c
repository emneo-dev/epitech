/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Check whether or not the given cell is on the upper side
*/

#include <bsq.h>

int is_upper_side(map_t mem, long int index)
{
    if (mem.columns - 1 >= index)
        return (1);
    return (0);
}
