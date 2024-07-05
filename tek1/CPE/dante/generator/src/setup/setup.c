/*
** EPITECH PROJECT, 2020
** generator
** File description:
** setup
*/

#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include "prototype.h"

static int setup_walls_perfect(generator_t *generator_o)
{
    if (setup_algo(generator_o))
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

static int setup_walls_imperfect(generator_t *generator_o)
{
    if (setup_algo(generator_o))
        return (EXIT_FAILURE);
    if (setup_broke_walls(generator_o))
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

int setup(generator_t *generator_o)
{
    if (generator_o->perfect == 1) {
        if (setup_walls_perfect(generator_o))
            return (EXIT_FAILURE);
    } else {
        if (setup_walls_imperfect(generator_o))
            return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}