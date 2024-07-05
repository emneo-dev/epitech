/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Set the value of the given map
*/

#include <bsq.h>
#include <stdio.h>

void my_set_value(map_t *mem, long int index)
{
    index = index;
    if (mem->mem[index] == 'o')
        mem->mem[index] = 0;
    else if (is_upper_side(*mem, index) || is_left_side(*mem, index))
        mem->mem[index] = 1;
    else
        mem->mem[index] = get_shortest(mem->mem[index - 1],
            mem->mem[index - mem->columns - 1],
            mem->mem[index - mem->columns - 2]) + 1;
    return;
}
