/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Convert index to 2d-vector
*/

#include <bsq.h>

vector2_t convert_to_v2(map_t mem, long int index)
{
    vector2_t ret;
    ret.x = (int)(index) % (mem.columns + 1);
    ret.y = (int)((index) / (mem.columns + 1)) + 1;
    return (ret);
}
