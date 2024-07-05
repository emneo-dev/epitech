/*
** EPITECH PROJECT, 2020
** generator
** File description:
** check_argument
*/

#include <stdlib.h>
#include "struct.h"
#include "prototype.h"

int check_argument(int ac, char **av, generator_t *generator_o)
{
    if (ac == 4)
        return (check_argument_perfect(av, generator_o));
    else if (ac == 3)
        return (check_argument_imperfect(av, generator_o));
    return (EXIT_FAILURE);
}