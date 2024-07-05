/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** printf clone
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my.h>

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
}

Test(sum_stdarg, return_correct_when_i_is_zero)
{
    int ret = sum_stdarg(0, 3, 21, 25, -4);

    cr_assert_eq(ret, 42);
}

Test(sum_stdarg, no_arguments_when_i_is_zero)
{
    int ret = sum_stdarg(0, 0);

    cr_assert_eq(ret, 0);
}

Test(sum_stdarg, return_correct_when_i_is_one)
{
    int ret = sum_stdarg(1, 5, "I", "like", "pastas", "and", "lasagna");

    cr_assert_eq(ret, 21);
}

Test(sum_stdarg, no_arguments_when_i_is_one)
{
    int ret = sum_stdarg(1, 0);

    cr_assert_eq(ret, 0);
}

Test(disp_stdarg, one_int, .init=redirect_all_stdout)
{
    disp_stdarg("i", 14);

    cr_assert_stdout_eq_str("14\n");
}

Test(disp_stdarg, multiple_types_from_example, .init=redirect_all_stdout)
{
    disp_stdarg("csiis", 'X', "hi", 10, -34, "plop");

    cr_assert_stdout_eq_str("X\nhi\n10\n-34\nplop\n");
}

Test(disp_stdarg, one_char_display, .init=redirect_all_stdout)
{
    disp_stdarg("c", 'X');

    cr_assert_stdout_eq_str("X\n");
}

Test(disp_stdarg, one_string_display, .init=redirect_all_stdout)
{
    disp_stdarg("s", "I like lasagnas");

    cr_assert_stdout_eq_str("I like lasagnas\n");
}