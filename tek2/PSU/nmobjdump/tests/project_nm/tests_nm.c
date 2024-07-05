/*
** EPITECH PROJECT, 2021
** nmobjdump
** File description:
** tests_nm
*/

#include <criterion/criterion.h>

#include "nm.h"

TestSuite(nm, .timeout = 1);

Test(nm, placeholder)
{
    int value = nm(0, NULL);

    cr_assert_eq(value, 0);
}