/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Return whether or not the given index is in the biggest square
*/

#include <bsq.h>
#include <stdio.h>

int is_in_square(map_t mem, long int highest, char the_highest, long int index)
{
    vector2_t coor = convert_to_v2(mem, index);
    vector2_t high = convert_to_v2(mem, highest);
    if ((coor.x > high.x - the_highest)
        && (coor.y > high.y - the_highest)
        && (coor.x <= high.x) && (coor.y <= high.y))
        return (1);
    return (0);
}
