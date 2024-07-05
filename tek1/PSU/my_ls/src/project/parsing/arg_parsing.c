/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** arg_parsing
*/

#include <stdlib.h>
#include "my.h"
#include "ls.h"

static args_t *init_parser(void)
{
    args_t *parsed_args = NULL;
    parsed_args = malloc(sizeof(args_t));
    if (!parsed_args)
        return (NULL);
    parsed_args->l_d = 0;
    parsed_args->l_l = 0;
    parsed_args->l_r = 0;
    parsed_args->l_t = 0;
    parsed_args->u_r = 0;
    parsed_args->paths = NULL;
    parsed_args->paths_len = 0;
    return (parsed_args);
}

static args_t *no_args(void)
{
    args_t *parsed_args = NULL;

    parsed_args = init_parser();
    if (!parsed_args)
        return (NULL);
    parsed_args->paths = malloc(sizeof(paths_t));
    if (!parsed_args->paths)
        return (NULL);
    parsed_args->paths->str = ".";
    parsed_args->paths->next = NULL;
    parsed_args->paths_len = 1;
    return (parsed_args);
}

int add_path(args_t *parsed_args, char const *new_path)
{
    paths_t *path = NULL;
    paths_t *original = parsed_args->paths;

    path = malloc(sizeof(paths_t));
    if (!path)
        return (1);
    path->next = NULL;
    path->str = malloc(sizeof(char) * (my_strlen(new_path) + 1));
    if (!path->str)
        return (1);
    my_strcpy(path->str, new_path);
    parsed_args->paths_len++;
    if (parsed_args->paths_len == 1)
        parsed_args->paths = path;
    else {
        for (; parsed_args->paths->next; parsed_args->paths =
        parsed_args->paths->next);
        parsed_args->paths->next = path;
        parsed_args->paths = original;
    }
    return (0);
}

static int arg_loop(args_t *parsed_args, char const *new_arg)
{
    if (new_arg[0] == '-' && my_strlen(new_arg) > 1) {
        if (add_flag(parsed_args, new_arg))
            return (1);
    }
    else
        if (add_path(parsed_args, new_arg))
            return (1);
    return (0);
}

args_t *parse_args(int argc, char const **argv)
{
    args_t *parsed_args = NULL;

    if (argc == 1)
        return (no_args());
    parsed_args = init_parser();
    if (!parsed_args)
        return (NULL);
    for (int i = 1; i < argc; i++)
        if (arg_loop(parsed_args, argv[i]) == 1)
            return (NULL);
    if (!parsed_args->paths_len)
        add_path(parsed_args, ".");
    return (parsed_args);
}