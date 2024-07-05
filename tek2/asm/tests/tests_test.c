/*
** EPITECH PROJECT, 2021
** asm
** File description:
** tests_test
*/

#include <criterion/criterion.h>

TestSuite(test_test, .timeout=1);

Test(test_test, basic_test)
{
    cr_assert_eq(1, 1);
}

Test(test_test, strlen)
{
    int ret = strlen("Issou");

    cr_assert_eq(ret, 5);
}