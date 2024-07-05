/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Test for the is_upper_side function
*/

#include <criterion/criterion.h>
#include <bsq.h>

Test(is_upper_side, is_on_top, .timeout=1)
{
    map_t mem;
    mem.columns = 42;
    cr_assert_eq(is_upper_side(mem, 21), 1);
}

Test(is_upper_side, is_not_on_top, .timeout=1)
{
    map_t mem;
    mem.columns = 42;
    cr_assert_eq(is_upper_side(mem, 84), 0);
}
