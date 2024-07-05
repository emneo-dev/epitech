/*
** EPITECH PROJECT, 2019
** pushswap_bootstrap
** File description:
** Test for the swap_elem function
*/

#include <pushswap_bs.h>
#include <criterion/criterion.h>

Test(swap_elem, array_of_2, .timeout = 1) {
    int array[2] = {42, 177013};
    cr_assert(array[0] == 42);
    cr_assert(array[1] == 177013);
    swap_elem(array, 0, 1);
    cr_assert(array[1] == 42);
    cr_assert(array[0] == 177013);
}
