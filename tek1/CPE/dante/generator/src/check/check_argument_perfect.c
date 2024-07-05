/*
** EPITECH PROJECT, 2020
** generator
** File description:
** check_argument_perfect
*/


#include <stdlib.h>
#include "my.h"
#include "struct.h"

int check_argument_perfect(char **av, generator_t *generator_o)
{
    if (my_str_isnum(av[1]) || my_str_isnum(av[2])
    || my_getnbr(av[1]) <= 0 || my_getnbr(av[2]) <= 0)
        return (EXIT_FAILURE);
    if (my_strcmp(av[3], "perfect"))
        return (EXIT_FAILURE);
    generator_o->x = my_getnbr(av[1]);
    generator_o->y = my_getnbr(av[2]);
    generator_o->perfect = 1;
    return (EXIT_SUCCESS);
}