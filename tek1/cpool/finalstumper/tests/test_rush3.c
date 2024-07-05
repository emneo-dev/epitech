/*
** EPITECH PROJECT, 2019
** CPool_finalstumper_2019
** File description:
** Test the finalstumper project
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <rush3.h>

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(rush3, rush1_1_with_4_5, .init=redirect_all_stdout)
{
    char *expected = "[rush1-1] 4 5\n";
    char *parameter = "o--o\n|  |\n|  |\n|  |\no--o\n";
    rush3(parameter);
    cr_assert_stdout_eq_str(expected, "");
}

Test(rush3, rush1_2_with_2_4, .init=redirect_all_stdout)
{
    char *expected = "[rush1-2] 2 4\n";
    char *parameter = "/\\\n**\n**\n\\/\n";
    rush3(parameter);
    cr_assert_stdout_eq_str(expected, "");
}

Test(rush3, rush1_3_with_2_4, .init=redirect_all_stdout)
{
    char *expected = "[rush1-3] 2 4\n";
    char *parameter = "AA\nBB\nBB\nCC\n";
    rush3(parameter);
    cr_assert_stdout_eq_str(expected, "");
}

Test(rush3, rush1_4_with_2_4, .init=redirect_all_stdout)
{
    char *expected = "[rush1-4] 2 4\n";
    char *parameter = "AC\nBB\nBB\nAC\n";
    rush3(parameter);
    cr_assert_stdout_eq_str(expected, "");
}

Test(rush3, rush1_5_with_2_4, .init=redirect_all_stdout)
{
    char *expected = "[rush1-5] 2 4\n";
    char *parameter = "AC\nBB\nBB\nCA\n";
    rush3(parameter);
    cr_assert_stdout_eq_str(expected, "");
}

Test(rush3, rush1_3_with_1_4, .init=redirect_all_stdout)
{
    char *expected = "[rush1-3] 1 4 || [rush1-4] 1 4 || [rush1-5] 1 4\n";
    char *parameter = "B\nB\nB\nB\n";
    rush3(parameter);
    cr_assert_stdout_eq_str(expected, "");
}

Test(rush3, rush1_2_with_4_1, .init=redirect_all_stdout)
{
    char *expected = "[rush1-2] 4 1\n";
    char *parameter = "****\n";
    rush3(parameter);
    cr_assert_stdout_eq_str(expected, "");
}

Test(rush3, rush1_4_with_4_1, .init=redirect_all_stdout)
{
    char *expected = "[rush1-3] 4 1 || [rush1-4] 4 1 || [rush1-5] 4 1\n";
    char *parameter = "BBBB\n";
    rush3(parameter);
    cr_assert_stdout_eq_str(expected, "");
}

Test(rush3, bad_input)
{
    char *parameter = "zbubzbub\n";
    int ret = rush3(parameter);
    cr_assert(84 == ret);
}
