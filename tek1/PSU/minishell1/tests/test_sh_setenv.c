/*
** EPITECH PROJECT, 2020
** PSU_minishell1 [WSL: Debian]
** File description:
** test_sh_setenv
*/

#include <criterion/criterion.h>
#include "sh.h"

Test(sh_setenv, setenv_one_arg, .timeout = 1)
{
    char *env[4] = {"issou=first", "aaa=bbb", "ccc=ddd", NULL};
    env_t *new_env = NULL;

    new_env = env_cpy(env);
    if (!new_env)
        cr_assert_fail();
    sh_setenv("setenv aled", &new_env);
    cr_expect_str_eq(new_env->data, "ccc=ddd");
    cr_expect_str_eq(new_env->next->data, "aaa=bbb");
    cr_expect_str_eq(new_env->next->next->data, "issou=first");
    cr_expect_str_eq(new_env->next->next->next->data, "aled=");
}

Test(sh_setenv, setenv_two_arg, .timeout = 1)
{
    char *env[4] = {"issou=first", "aaa=bbb", "ccc=ddd", NULL};
    env_t *new_env = NULL;

    new_env = env_cpy(env);
    if (!new_env)
        cr_assert_fail();
    sh_setenv("setenv aled ausscour", &new_env);
    cr_expect_str_eq(new_env->data, "ccc=ddd");
    cr_expect_str_eq(new_env->next->data, "aaa=bbb");
    cr_expect_str_eq(new_env->next->next->data, "issou=first");
    cr_expect_str_eq(new_env->next->next->next->data, "aled=ausscour");
}

Test(sh_setenv, setenv_two_arg_existing, .timeout = 1)
{
    char *env[4] = {"issou=first", "aaa=bbb", "ccc=ddd", NULL};
    env_t *new_env = NULL;

    new_env = env_cpy(env);
    if (!new_env)
        cr_assert_fail();
    sh_setenv("setenv issou ausscour", &new_env);
    cr_expect_str_eq(new_env->data, "ccc=ddd");
    cr_expect_str_eq(new_env->next->data, "aaa=bbb");
    cr_expect_str_eq(new_env->next->next->data, "issou=ausscour");
}