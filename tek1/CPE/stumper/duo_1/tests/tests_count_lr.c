/*
** EPITECH PROJECT, 2020
** duostumper
** File description:
** test_count_lr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "duo.h"

Test(count_lr, number_lr_3, .timeout = 1)
{
    int tmp = count_lr("I\nlike\nlasagnas\n");

    cr_expect_eq(tmp, 3);
}

Test(byte_display, null_str, .timeout = 1)
{
    int tmp = count_lr(NULL);

    cr_expect_eq(tmp, 0);
}
