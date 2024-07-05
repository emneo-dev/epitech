/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** test_is_a_builtin
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "sh.h"

Test(is_a_builtin, cd_alone, .timeout = 1)
{
    int return_value = 0;

    return_value = is_a_builtin("cd");
    cr_assert_eq(return_value, 1);
}

Test(is_a_builtin, setenv_alone, .timeout = 1)
{
    int return_value = 0;

    return_value = is_a_builtin("setenv");
    cr_assert_eq(return_value, 1);
}

Test(is_a_builtin, unsetenv_alone, .timeout = 1)
{
    int return_value = 0;

    return_value = is_a_builtin("unsetenv");
    cr_assert_eq(return_value, 1);
}

Test(is_a_builtin, env_alone, .timeout = 1)
{
    int return_value = 0;

    return_value = is_a_builtin("env");
    cr_assert_eq(return_value, 1);
}

Test(is_a_builtin, exit_alone, .timeout = 1)
{
    int return_value = 0;

    return_value = is_a_builtin("exit");
    cr_assert_eq(return_value, 1);
}

Test(is_a_builtin, exi_typo, .timeout = 1)
{
    int return_value = 0;

    return_value = is_a_builtin("exi");
    cr_assert_eq(return_value, 0);
}

Test(is_a_builtin, exi_t_typo, .timeout = 1)
{
    int return_value = 0;

    return_value = is_a_builtin("exi t");
    cr_assert_eq(return_value, 0);
}

Test(is_a_builtin, exit_1_arg, .timeout = 1)
{
    int return_value = 0;

    return_value = is_a_builtin("exit 177013");
    cr_assert_eq(return_value, 1);
}

Test(is_a_builtin, setenv_1_arg, .timeout = 1)
{
    int return_value = 0;

    return_value = is_a_builtin("setenv hh");
    cr_assert_eq(return_value, 1);
}

Test(is_a_builtin, unsetenv_1_arg, .timeout = 1)
{
    int return_value = 0;

    return_value = is_a_builtin("unsetenv hh");
    cr_assert_eq(return_value, 1);
}