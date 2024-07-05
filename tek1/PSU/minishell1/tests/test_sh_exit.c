/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** test_sh_exit
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "sh.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(sh_exit, no_arg, .timeout = 1)
{
    env_t *ep = NULL;
    result_t return_value = {0, 0};

    return_value = sh_exit("exit", &ep);
    cr_expect_eq(return_value.do_exit, 1);
    cr_expect_eq(return_value.status, 0);
}

Test(sh_exit, one_arg_84, .timeout = 1)
{
    env_t *ep = NULL;
    result_t return_value = {0, 0};

    return_value = sh_exit("exit 84", &ep);
    cr_expect_eq(return_value.do_exit, 1);
    cr_expect_eq(return_value.status, 84);
}

Test(sh_exit, one_arg_minus_1, .timeout = 1)
{
    env_t *ep = NULL;
    result_t return_value = {0, 0};

    return_value = sh_exit("exit -1", &ep);
    cr_expect_eq(return_value.do_exit, 1);
    cr_expect_eq(return_value.status, 255);
}

Test(sh_exit, one_arg_84_more_space, .timeout = 1)
{
    env_t *ep = NULL;
    result_t return_value = {0, 0};

    return_value = sh_exit("exit                  84", &ep);
    cr_expect_eq(return_value.do_exit, 1);
    cr_expect_eq(return_value.status, 84);
}

Test(sh_exit, one_arg_84_more_space_with_tab, .timeout = 1)
{
    env_t *ep = NULL;
    result_t return_value = {0, 0};

    return_value = sh_exit("exit     \t    \t  \t       84", &ep);
    cr_expect_eq(return_value.do_exit, 1);
    cr_expect_eq(return_value.status, 84);
}

Test(sh_exit, wrong_arg_badly_number, .init=redirect_all_stdout, .timeout = 1)
{
    env_t *ep = NULL;
    result_t return_value = {0, 0};

    return_value = sh_exit("exit 1-1", &ep);
    cr_expect_stdout_eq_str("exit: Badly formed number.\n");
    cr_expect_eq(return_value.do_exit, 0);
    cr_expect_eq(return_value.status, 0);
}

Test(sh_exit, wrong_arg_badly_number_2, .init=redirect_all_stdout, .timeout = 1)
{
    env_t *ep = NULL;
    result_t return_value = {0, 0};

    return_value = sh_exit("exit -1aaa", &ep);
    cr_expect_stdout_eq_str("exit: Badly formed number.\n");
    cr_expect_eq(return_value.do_exit, 0);
    cr_expect_eq(return_value.status, 0);
}

Test(sh_exit, wrong_arg_expression, .init=redirect_all_stdout, .timeout = 1)
{
    env_t *ep = NULL;
    result_t return_value = {0, 0};

    return_value = sh_exit("exit +", &ep);
    cr_expect_stdout_eq_str("exit: Expression Syntax.\n");
    cr_expect_eq(return_value.do_exit, 0);
    cr_expect_eq(return_value.status, 0);
}

Test(sh_exit, too_many_arg, .init=redirect_all_stdout, .timeout = 1)
{
    env_t *ep = NULL;
    result_t return_value = {0, 0};

    return_value = sh_exit("exit 0 0", &ep);
    cr_expect_stdout_eq_str("exit: Expression Syntax.\n");
    cr_expect_eq(return_value.do_exit, 0);
    cr_expect_eq(return_value.status, 0);
}

Test(sh_exit, wrong_arg_badly_number_3, .init=redirect_all_stdout, .timeout = 1)
{
    env_t *ep = NULL;
    result_t return_value = {0, 0};

    return_value = sh_exit("exit --", &ep);
    cr_expect_stdout_eq_str("exit: Badly formed number.\n");
    cr_expect_eq(return_value.do_exit, 0);
    cr_expect_eq(return_value.status, 0);
}

Test(sh_exit, wrong_arg_badly_number_4, .init=redirect_all_stdout, .timeout = 1)
{
    env_t *ep = NULL;
    result_t return_value = {0, 0};

    return_value = sh_exit("exit 5:", &ep);
    cr_expect_stdout_eq_str("exit: Badly formed number.\n");
    cr_expect_eq(return_value.do_exit, 0);
    cr_expect_eq(return_value.status, 0);
}

Test(sh_exit, wrong_arg_badly_number_5, .init=redirect_all_stdout, .timeout = 1)
{
    env_t *ep = NULL;
    result_t return_value = {0, 0};

    return_value = sh_exit("exit -1-", &ep);
    cr_expect_stdout_eq_str("exit: Badly formed number.\n");
    cr_expect_eq(return_value.do_exit, 0);
    cr_expect_eq(return_value.status, 0);
}

Test(sh_exit, wrong_arg_badly_number_6, .init=redirect_all_stdout, .timeout = 1)
{
    env_t *ep = NULL;
    result_t return_value = {0, 0};

    return_value = sh_exit("exit 1-", &ep);
    cr_expect_stdout_eq_str("exit: Badly formed number.\n");
    cr_expect_eq(return_value.do_exit, 0);
    cr_expect_eq(return_value.status, 0);
}

Test(sh_exit, wrong_arg_expression_2, .init=redirect_all_stdout, .timeout = 1)
{
    env_t *ep = NULL;
    result_t return_value = {0, 0};

    return_value = sh_exit("exit +2", &ep);
    cr_expect_stdout_eq_str("exit: Expression Syntax.\n");
    cr_expect_eq(return_value.do_exit, 0);
    cr_expect_eq(return_value.status, 0);
}

Test(sh_exit, wrong_arg_expression_3, .init=redirect_all_stdout, .timeout = 1)
{
    env_t *ep = NULL;
    result_t return_value = {0, 0};

    return_value = sh_exit("exit aaa", &ep);
    cr_expect_stdout_eq_str("exit: Expression Syntax.\n");
    cr_expect_eq(return_value.do_exit, 0);
    cr_expect_eq(return_value.status, 0);
}