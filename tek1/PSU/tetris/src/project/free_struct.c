/*
** EPITECH PROJECT, 2020
** PSU_tetris
** File description:
** free_struct
*/

#include <stdlib.h>
#include "struct.h"

static void free_args(args_t *args)
{
    free(args->map_size);
    free(args);
}

static void free_tetr(tetr_t *tetr)
{
    free(tetr->name);
    free(tetr);
}

int free_struct(args_t *args, tetr_t *tetr)
{
    free_args(args);
    free_tetr(tetr);
    return (EXIT_SUCCESS);
}
