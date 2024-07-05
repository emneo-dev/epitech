/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** test_my_str_split
*/

#include <criterion/criterion.h>
#include "sh.h"

Test(my_str_split, normal_path_double_dot, .timeout = 1)
{
    char *arg = "/usr/bin:/bin:/local/bin";
    char **splited = NULL;

    splited = my_str_split(arg, ':');
    cr_expect_str_eq(splited[0], "/usr/bin");
    cr_expect_str_eq(splited[1], "/bin");
    cr_expect_str_eq(splited[2], "/local/bin");
}

Test(my_str_split, weird_path_double_dot, .timeout = 1)
{
    char *arg = "/usr/bin::/bin::::::/local/bin";
    char **splited = NULL;

    splited = my_str_split(arg, ':');
    cr_expect_str_eq(splited[0], "/usr/bin");
    cr_expect_str_eq(splited[1], "/bin");
    cr_expect_str_eq(splited[2], "/local/bin");
}

Test(my_str_split, null_arg, .timeout = 1)
{
    char *arg = NULL;
    char **splited = NULL;

    splited = my_str_split(arg, ':');
    cr_expect_eq(splited, NULL);
}