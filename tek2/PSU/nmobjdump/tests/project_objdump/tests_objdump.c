/*
** EPITECH PROJECT, 2021
** nmobjdump
** File description:
** tests_objdump
*/

#include <criterion/criterion.h>

#include "objdump.h"

TestSuite(objdump, .timeout = 1);

Test(objdump, placeholder)
{
    int value = objdump(0, NULL);

    cr_assert_eq(value, 0);
}