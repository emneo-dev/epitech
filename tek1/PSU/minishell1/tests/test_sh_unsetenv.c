/*
** EPITECH PROJECT, 2020
** PSU_minishell1 [WSL: Debian]
** File description:
** test_sh_unsetenv
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "sh.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(sh_unsetenv, unsetenv_one_arg, .timeout = 1)
{
    char *env[4] = {"issou=first", "aaa=bbb", "ccc=ddd", NULL};
    env_t *new_env = NULL;

    new_env = env_cpy(env);
    if (!new_env)
        cr_assert_fail();
    sh_unsetenv("unsetenv issou", &new_env);
    cr_expect_str_eq(new_env->data, "ccc=ddd");
    cr_expect_str_eq(new_env->next->data, "aaa=bbb");
    cr_expect_eq(new_env->next->next, NULL);
}

Test(sh_unsetenv, unsetenv_no_arg, .init = redirect_all_stdout, .timeout = 1)
{
    char *env[4] = {"issou=first", "aaa=bbb", "ccc=ddd", NULL};
    env_t *new_env = NULL;

    new_env = env_cpy(env);
    if (!new_env)
        cr_assert_fail();
    sh_unsetenv("unsetenv", &new_env);
    cr_expect_stdout_eq_str("unsetenv: Too few arguments.\n");
}

Test(sh_unsetenv, unsetenv_one_arg_beginning, .timeout = 1)
{
    char *env[4] = {"issou=first", "aaa=bbb", "ccc=ddd", NULL};
    env_t *new_env = NULL;

    new_env = env_cpy(env);
    if (!new_env)
        cr_assert_fail();
    sh_unsetenv("unsetenv ccc", &new_env);
    cr_expect_str_eq(new_env->data, "aaa=bbb");
    cr_expect_str_eq(new_env->next->data, "issou=first");
    cr_expect_eq(new_env->next->next, NULL);
}