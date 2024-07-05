/*
** EPITECH PROJECT, 2020
** sample_project
** File description:
** sample
*/

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "prototype.h"

int tetris(int argc, char **argv)
{
    args_t *args = NULL;
    tetr_t *tetr = NULL;

    args = arg_parsing(argc, argv, init_args());
    if (!args)
        return (84);
    if (args->help) {
        helper();
        return (free_struct(args, tetr));
    }
    tetr = tetr_parsing();
    if (!tetr)
        return (84);
    if ((args->debug))
        return (debug(args, tetr));
    else
        return (game(args, tetr));
    return (0);
}