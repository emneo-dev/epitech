/*
** EPITECH PROJECT, 2020
** duostumper
** File description:
** test_byte_display
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "duo.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(byte_display, basic_file_8_bytes, .init = redirect_all_stdout,
        .timeout = 1)
{
    int tmp = byte_display(8, "./tests/tests_files/basic_file");

    cr_expect_stdout_eq_str("I like l");
    cr_expect_eq(tmp, 0);
}

Test(byte_display, incorrect_file, .timeout = 1)
{
    int tmp = byte_display(8, "issou");

    cr_expect_eq(tmp, 1);
}
