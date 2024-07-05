/*
** EPITECH PROJECT, 2019
** pushswap_bootstrap
** File description:
** Test for the bubble_sort_array function
*/

#include <pushswap_bs.h>
#include <criterion/criterion.h>

Test(bubble_sort_array, array_of_8_sorted, .timeout = 1) {
    int array[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    int expected[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    bubble_sort_array(array, 8);
    cr_assert_arr_eq(array, expected, 8);
}

Test(bubble_sort_array, array_of_8, .timeout = 1) {
    int array[8] = {7, 3, 2, 1, 6, 5, 4, 0};
    int expected[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    bubble_sort_array(array, 8);
    cr_assert_arr_eq(array, expected, 8);
}
