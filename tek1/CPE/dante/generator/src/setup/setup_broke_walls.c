/*
** EPITECH PROJECT, 2020
** generator
** File description:
** setup_broke_walls
*/

#include <stdlib.h>
#include "struct.h"

int setup_broke_walls(generator_t *generator_o)
{
    int x = 0;
    int y = 0;

    for (int i = 0; i < generator_o->unwated_walls; i++) {
        x = rand()%(generator_o->x);
        y = rand()%(generator_o->y);
        if (generator_o->map[y][x] == 'X')
            generator_o->map[y][x] = '*';
    }
    return (EXIT_SUCCESS);
}