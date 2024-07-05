/*
** EPITECH PROJECT, 2020
** generator
** File description:
** init_map
*/

#include <stdlib.h>
#include "struct.h"

static int init_way(generator_t *generator_o, int i, int j)
{
    if (j % 2 == 0 && i % 2 == 0)
        generator_o->map[i][j] = '*';
    if (j % 2 != 0 && i % 2 == 0)
        generator_o->map[i][j] = 'X';
    else if (i % 2 != 0)
        generator_o->map[i][j] = 'X';
    return (j);
}

int init_map(generator_t *generator_o)
{
    int j = 0;

    for (int i = 0; i < generator_o->y; i++) {
        j = 0;
        for (; j < generator_o->x; j++) {
            init_way(generator_o, i, j);
        }
        generator_o->map[i][j] = '\0';
    }
    return (EXIT_SUCCESS);
}