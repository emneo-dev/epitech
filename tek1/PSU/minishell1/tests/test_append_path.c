/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** test_append_path
*/

#include <criterion/criterion.h>
#include "my.h"
#include "sh.h"

Test(append_path, two_normal_str, .timeout = 1)
{
    char *first = "halp";
    char *second = "aled";
    char *result = NULL;

    result = append_path(first, second);
    cr_expect_str_eq(result, "halp/aled");
}

Test(append_path, first_null, .timeout = 1)
{
    char *first = NULL;
    char *second = "aled";
    char *result = NULL;

    result = append_path(first, second);
    cr_expect_str_eq(result, "/aled");
}

Test(append_path, second_null, .timeout = 1)
{
    char *first = "halp";
    char *second = NULL;
    char *result = NULL;

    result = append_path(first, second);
    cr_expect_str_eq(result, "halp/");
}