/*
** EPITECH PROJECT, 2020
** duostumper
** File description:
** arg_parsing
*/

#include <stdlib.h>
#include "my.h"
#include "duo.h"

args_t *arg_parsing(int argc, char const **argv)
{
    args_t *args = NULL;

    args = malloc(sizeof(args_t));
    args->c = 8;
    args->n = 0;
    args->q = 0;
    args->v = 0;
    args->paths_len = 1;
    args->paths = malloc(sizeof(paths_t));
    args->paths->str = my_strdup(argv[1]);
    args->paths->next = NULL;
    (void)argc;
    (void)argv;
    return (args);
}
