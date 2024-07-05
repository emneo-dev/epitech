/*
** EPITECH PROJECT, 2020
** generator
** File description:
** setup_algo
*/

#include <stdlib.h>
#include "struct.h"

static void setup_north_west(generator_t *generator_o, int i, int j)
{
    if (i - 1 >= 0 && generator_o->map[i - 1][j] == 'X')
        generator_o->n = 1;
    if (j - 1 >= 0 && generator_o->map[i][j - 1] == 'X')
        generator_o->w = 1;
}

static void setup_one_wall(generator_t *generator_o, int i, int j)
{
    if (i - 1 >= 0 && generator_o->n == 1 && generator_o->w == 0)
        generator_o->map[i - 1][j] = '*';
    if (j - 1 >= 0 && generator_o->n == 0 && generator_o->w == 1)
        generator_o->map[i][j - 1] = '*';
}

static void setup_two_walls(generator_t *generator_o, int i, int j, int r)
{
    r = rand()%2;
    if (j - 1 >= 0 && r == 0)
        generator_o->map[i][j - 1] = '*';
    if (i - 1 >= 0 && r == 1)
        generator_o->map[i - 1][j] = '*';
}

static void setup_walls(generator_t *generator_o, int i, int j, int r)
{
    setup_north_west(generator_o, i, j);
    setup_one_wall(generator_o, i, j);
    if (generator_o->n == 1 && generator_o->w == 1)
        setup_two_walls(generator_o, i, j, r);
}

int setup_algo(generator_t *generator_o)
{
    int r = 0;

    for (int i = 0; i < generator_o->y; i = i + 2) {
        generator_o->n = 0;
        generator_o->w = 0;
        for (int j = 0; j < generator_o->x; j = j + 2) {
            if (i == 0)
                generator_o->map[i][j] = '*';
            setup_walls(generator_o, i, j, r);
        }
    }
    return (EXIT_SUCCESS);
}