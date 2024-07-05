/*
** EPITECH PROJECT, 2020
** sample_project
** File description:
** main
*/

#include <stdlib.h>
#include <unistd.h>
#include "struct.h"
#include "prototype.h"
#include "my.h"

static void display_map(generator_t *generator_o)
{
    int i = 0;

    if (generator_o->x != 1 || generator_o->y != 1) {
        if (generator_o->map[generator_o->y - 1][generator_o->x - 1] == 'X')
            generator_o->map[generator_o->y - 1][generator_o->x - 1] = '*';
        if (generator_o->map[generator_o->y - 1][generator_o->x - 1] == '*'
        && generator_o->map[generator_o->y - 1][generator_o->x - 2] == 'X'
        && generator_o->map[generator_o->y - 2][generator_o->x - 1] == 'X')
            generator_o->map[generator_o->y - 1][generator_o->x - 2] = '*';
    }
    if (generator_o->x == 2 && generator_o->y == 2
    && generator_o->perfect == 0) {
        if (generator_o->map[generator_o->y - 1][generator_o->x - 2] == 'X')
            generator_o->map[generator_o->y - 1][generator_o->x - 2] = '*';
    }
    for (; i < generator_o->y - 1; i++) {
        write(1, generator_o->map[i], my_strlen(generator_o->map[i]));
        write(1, "\n", 1);
    }
    write(1, generator_o->map[i], my_strlen(generator_o->map[i]));
}

static void free_every_malloc(generator_t *generator_o)
{
    for (int i = 0; i < generator_o->y; i++)
        free(generator_o->map[i]);
    free(generator_o->map);
    free(generator_o);
}

int main(int ac, char **av)
{
    generator_t *generator_o = malloc(sizeof(*generator_o));
    if (!generator_o)
        return (84);
    if (check_argument(ac, av, generator_o)) {
        free(generator_o);
        return (84);
    }
    if (init(generator_o)) {
        free(generator_o);
        return (84);
    }
    if (setup(generator_o)) {
        free_every_malloc(generator_o);
        return (84);
    }
    display_map(generator_o);
    free_every_malloc(generator_o);
    return (EXIT_SUCCESS);
}