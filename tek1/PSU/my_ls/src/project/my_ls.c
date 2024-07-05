/*
** EPITECH PROJECT, 2020
** sample_project
** File description:
** sample
*/

#include "ls.h"

int my_ls(int argc, char const **argv)
{
    args_t *parsed_args = NULL;

    parsed_args = parse_args(argc, argv);
    if (!parsed_args)
        return (84);
    if (parsed_args->u_r)
        ur_flag(parsed_args);
    print_ls(parsed_args);
    return (0);
}