/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Tests for the is_left_side function
*/

#include <criterion/criterion.h>
#include <bsq.h>

Test(is_left_side, is_on_left, .timeout=1)
{
    map_t mem;
    mem.columns = 42;
    cr_assert_eq(is_left_side(mem, 0), 1);
    cr_assert_eq(is_left_side(mem, 43), 1);
    cr_assert_eq(is_left_side(mem, 86), 1);
}

Test(is_left_side, is_not_on_left, .timeout=1)
{
    map_t mem;
    mem.columns = 42;
    cr_assert_eq(is_left_side(mem, 36), 0);
    cr_assert_eq(is_left_side(mem, 300), 0);
}
