/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD03-alexandre.flion [SSH: 192.168.0.19]
** File description:
** tests_split
*/

#include <criterion/criterion.h>

#include "../string.h"

TestSuite(split, .timeout=1);

Test(split, hole_in_splits)
{
    string_t s;
    char **tmp = NULL;

    string_init(&s, "monday,,wednesday,thursday,friday,saturday,sunday");
    tmp = s.split_c(&s, ',');
    cr_assert_not_null(tmp);
    cr_expect_str_eq(tmp[0], "monday");
    cr_expect_str_eq(tmp[1], "");
    cr_expect_str_eq(tmp[2], "wednesday");
    cr_expect_str_eq(tmp[3], "thursday");
    cr_expect_str_eq(tmp[4], "friday");
    cr_expect_str_eq(tmp[5], "saturday");
    cr_expect_str_eq(tmp[6], "sunday");
}