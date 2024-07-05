/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** test_get_splited_path
*/

#include <criterion/criterion.h>
#include "sh.h"

Test(get_splited_path, just_path_in_env_3, .timeout = 1)
{
    char *path = "PATH=/bin:/usr/bin:/local/bin";
    char **env = &path;
    char **splited_path = NULL;

    splited_path = get_splited_path(env);
    cr_assert_neq(splited_path, NULL);
    cr_expect_str_eq(splited_path[0], "/bin");
    cr_expect_str_eq(splited_path[1], "/usr/bin");
    cr_expect_str_eq(splited_path[2], "/local/bin");
}

Test(get_splited_path, just_path_in_env_2, .timeout = 1)
{
    char *path = "PATH=/bin:/usr/bin";
    char **env = &path;
    char **splited_path = NULL;

    splited_path = get_splited_path(env);
    cr_assert_neq(splited_path, NULL);
    cr_expect_str_eq(splited_path[0], "/bin");
    cr_expect_str_eq(splited_path[1], "/usr/bin");
}

Test(get_splited_path, just_path_in_env_1, .timeout = 1)
{
    char *path = "PATH=/bin";
    char **env = &path;
    char **splited_path = NULL;

    splited_path = get_splited_path(env);
    cr_assert_neq(splited_path, NULL);
    cr_expect_str_eq(splited_path[0], "/bin");
}

Test(get_splited_path, empty_path, .timeout = 1)
{
    char *path = "PATH=";
    char **env = &path;
    char **splited_path = NULL;

    splited_path = get_splited_path(env);
    cr_assert_neq(splited_path, NULL);
    cr_expect_eq(splited_path[0], NULL);
}

Test(get_splited_path, null_path, .timeout = 1)
{
    char **env = NULL;
    char **splited_path = NULL;

    splited_path = get_splited_path(env);
    cr_assert_eq(splited_path, NULL);
}