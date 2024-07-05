/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** test_print_prompt
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "sh.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(print_prompt, normal_call, .init=redirect_all_stdout, .timeout = 1)
{
    print_prompt();

    cr_assert_stdout_eq_str("( ͡° ͜ʖ ͡°) $ -> ");
}