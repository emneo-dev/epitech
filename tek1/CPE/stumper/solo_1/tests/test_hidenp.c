/*
** EPITECH PROJECT, 2019
** CPE_solostumper_1_2019
** File description:
** Tests for the hidenp project
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "hidenp.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
}

Test(hidenp, first_example, .init=redirect_all_stdout)
{
    int tmp = find_needle("padinton", "paqefwtdjetyiytjneytjoeyjnejeyj");

    cr_assert_stdout_eq_str("1\n");
    cr_assert_eq(tmp, 0);
}

Test(hidenp, no_match, .init=redirect_all_stdout)
{
    int tmp = find_needle("fezjgifzijg", "paqefwtdjetyiytjneytjoeyjnejeyj");

    cr_assert_stdout_eq_str("0\n");
    cr_assert_eq(tmp, 0);
}

Test(hidenp, empty_strings, .init=redirect_all_stdout)
{
    int tmp = find_needle("", "");

    cr_assert_stdout_eq_str("1\n");
    cr_assert_eq(tmp, 0);
}

Test(hidenp, one_letter_missing, .init=redirect_all_stdout)
{
    int tmp = find_needle("padinnton", "padinton");

    cr_assert_stdout_eq_str("0\n");
    cr_assert_eq(tmp, 0);
}

Test(hidenp, one_letter_more, .init=redirect_all_stdout)
{
    int tmp = find_needle("padinton", "padinnton");

    cr_assert_stdout_eq_str("1\n");
    cr_assert_eq(tmp, 0);
}
