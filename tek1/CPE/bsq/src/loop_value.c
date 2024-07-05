/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Loop through the memory to set their value
*/

#include <bsq.h>

void loop_value(map_t *mem)
{
    for (int i = 0; mem->mem[i] != '\0'; i++)
        if (mem->mem[i] != '\n')
            my_set_value(mem, i);
    return;
}
