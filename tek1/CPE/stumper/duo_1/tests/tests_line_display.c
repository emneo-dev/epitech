/*
** EPITECH PROJECT, 2020
** duostumper
** File description:
** tests_line_display
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "duo.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(line_display, two_lines, .init = redirect_all_stdout, .timeout = 1)
{
    int tmp = line_display(2, "./tests/tests_files/basic_file");

    cr_expect_stdout_eq_str("I like lasagnas\nThis is why I eat some everyday\n");
    cr_expect_eq(tmp, 0);
}


Test(put_lines, two_lines_with_3, .init = redirect_all_stdout,
        .timeout = 1)
{
    char *buffer = "aaa\nbbb\nccc\n";

    int tmp = put_lines(2, buffer);
    cr_expect_stdout_eq_str("aaa\nbbb\n");
    cr_expect_eq(tmp, 0);
}
