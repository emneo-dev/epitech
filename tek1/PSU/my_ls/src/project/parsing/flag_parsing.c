/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** flag_parsing
*/

#include "my.h"
#include "ls.h"

static int flag_loop(args_t *parsed_args, char const new_flag)
{
    switch (new_flag) {
    case 'l':
        parsed_args->l_l = 1;
        break;
    case 'R':
        parsed_args->u_r = 1;
        break;
    case 't':
        parsed_args->l_t = 1;
        break;
    case 'r':
        parsed_args->l_r = 1;
        break;
    case 'd':
        parsed_args->l_d = 1;
        break;
    default:
        return (1);
    }
    return (0);
}

int add_flag(args_t *parsed_args, char const *new_flag)
{
    for (int i = 1; new_flag[i]; i++)
        if (flag_loop(parsed_args, new_flag[i])) {
            my_putstr("my_ls: invalid option -- ");
            my_putchar(new_flag[i]);
            my_putstr("\nTry './my_ls --help' for more information.\n");
            return (1);
        }
    return (0);
}