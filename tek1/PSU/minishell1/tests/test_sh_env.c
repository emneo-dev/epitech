/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** test_sh_env
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "sh.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(sh_env, no_arg_2_env, .init=redirect_all_stdout, .timeout = 1)
{
    env_t *ep_first = NULL;
    env_t *ep_second = NULL;
    char *first = "zbub";
    char *second = "hhhhh";
    result_t return_value = {0, 0};

    ep_first = malloc(sizeof(env_t));
    ep_second = malloc(sizeof(env_t));
    if (!ep_first)
        cr_assert(0);
    if (!ep_second)
        cr_assert(0);
    ep_first->data = first;
    ep_first->next = ep_second;
    ep_second->data = second;
    ep_second->next = NULL;
    return_value = sh_env("env", &ep_first);
    cr_expect_stdout_eq_str("zbub\nhhhhh\n");
    cr_expect_eq(return_value.do_exit, 0);
    cr_expect_eq(return_value.status, 0);
}

Test(sh_env, no_arg_1_env, .init=redirect_all_stdout, .timeout = 1)
{
    env_t *ep = NULL;
    char *first = "zbub";
    result_t return_value = {0, 0};

    ep = malloc(sizeof(env_t));
    if (!ep)
        cr_assert(0);
    ep->data = first;
    ep->next = NULL;
    return_value = sh_env("env", &ep);
    cr_expect_stdout_eq_str("zbub\n");
    cr_expect_eq(return_value.do_exit, 0);
    cr_expect_eq(return_value.status, 0);
}

Test(sh_env, no_arg_no_env, .init=redirect_all_stdout, .timeout = 1)
{
    env_t *ep = NULL;
    result_t return_value = {0, 0};

    return_value = sh_env("env", &ep);
    cr_expect_eq(return_value.do_exit, 0);
    cr_expect_eq(return_value.status, 0);
}