/*
** EPITECH PROJECT, 2020
** generator
** File description:
** init
*/

#include <stdlib.h>
#include "struct.h"
#include "prototype.h"

int init(generator_t *generator_o)
{
    if (init_malloc_map(generator_o))
        return (EXIT_FAILURE);
    if (init_map(generator_o))
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}