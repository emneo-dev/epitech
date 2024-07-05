/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD03-alexandre.flion
** File description:
** tests_copy
*/

#include <criterion/criterion.h>

#include "../string.h"

TestSuite(copy, .timeout=1);

Test(copy, non_complete_string)
{
    string_t s;
    size_t len_copied = 0;
    char string[100] = {0};

    string_init(&s, "My string");
    len_copied = s.copy(&s, string, 5, 0);
    cr_expect_eq(len_copied, 5);
    cr_expect_str_eq(string, "My st");
}

Test(copy, complete_string)
{
    string_t s;
    size_t len_copied = 0;
    char string[100] = {0};

    string_init(&s, "My string");
    len_copied = s.copy(&s, string, 50, 0);
    cr_expect_eq(len_copied, 10);
    cr_expect_str_eq(string, "My string");
}

Test(copy, complete_string_no_null_terminating_byte)
{
    string_t s;
    size_t len_copied = 0;
    char string[100] = {0};

    string_init(&s, "My string");
    len_copied = s.copy(&s, string, 9, 0);
    cr_expect_eq(len_copied, 9);
    cr_expect_str_eq(string, "My string");
}