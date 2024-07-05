/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** test_append
*/

#include <criterion/criterion.h>
#include "my.h"
#include "sh.h"

Test(append, two_normal_str, .timeout = 1)
{
    char *first = "=";
    char *second = "aled";
    char *result = NULL;

    result = append(first, second);
    cr_expect_str_eq(result, "=aled");
}

Test(append, first_null, .timeout = 1)
{
    char *first = NULL;
    char *second = "aled";
    char *result = NULL;

    result = append(first, second);
    cr_expect_str_eq(result, "aled");
}

Test(append, second_null, .timeout = 1)
{
    char *first = "halp";
    char *second = NULL;
    char *result = NULL;

    result = append(first, second);
    cr_expect_str_eq(result, "halp");
}