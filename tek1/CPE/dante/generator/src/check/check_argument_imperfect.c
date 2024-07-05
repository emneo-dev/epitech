/*
** EPITECH PROJECT, 2020
** generator
** File description:
** check_argument_imperfect
*/

#include <stdlib.h>
#include "my.h"
#include "struct.h"

int check_argument_imperfect(char **av, generator_t *generator_o)
{
    if (my_str_isnum(av[1]) || my_str_isnum(av[2])
    || my_getnbr(av[1]) <= 0 || my_getnbr(av[2]) <= 0)
        return(EXIT_FAILURE);
    generator_o->x = my_getnbr(av[1]);
    generator_o->y = my_getnbr(av[2]);
    generator_o->unwated_walls  = (my_getnbr(av[1]) * my_getnbr(av[2])) / 2;
    generator_o->perfect = 0;
    return (EXIT_SUCCESS);
}