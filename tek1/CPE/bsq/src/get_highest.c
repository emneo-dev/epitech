/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Get highest number in pre-processed map
*/

#include <bsq.h>

size_t get_highest(map_t mem)
{
    size_t ret_highest = -1;
    char highest = 0;
    for (size_t i = 0; i <= mem.size; i++) {
        if (mem.mem[i] > highest && mem.mem[i] != '\n') {
            ret_highest = i;
            highest = mem.mem[i];
        }
    }
    return (ret_highest);
}