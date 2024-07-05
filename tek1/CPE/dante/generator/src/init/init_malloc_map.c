/*
** EPITECH PROJECT, 2020
** generator
** File description:
** init_malloc_map
*/

#include <stdlib.h>
#include "struct.h"

int init_malloc_map(generator_t *generator_o)
{
    int i = 0;

    generator_o->map = malloc(sizeof(char*) * (generator_o->y) + 1);
    if (!(generator_o->map))
        return (EXIT_FAILURE);
    for (; i < generator_o->y; i++) {
        generator_o->map[i] = malloc(sizeof(char*) * (generator_o->x));
        if (!(generator_o->map[i]))
            return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}