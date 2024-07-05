/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019 [WSL: Ubuntu]
** File description:
** test_char_to_int_ll
*/

#include <criterion/criterion.h>
#include "pushswap.h"

Test(char_to_int_ll, normal_uint, .timeout=1)
{
    char *params[6] = {"exe", "5", "4", "3", "2", "1"};
    t_link_t *current = char_to_int_ll(6, params);
    cr_assert_eq(5, current->value);
    cr_assert_eq(4, current->next->value);
    cr_assert_eq(3, current->next->next->value);
    cr_assert_eq(2, current->next->next->next->value);
    cr_assert_eq(1, current->next->next->next->next->value);
}

Test(char_to_int_ll, normal_int, .timeout=1)
{
    char *params[6] = {"exe", "5", "4", "-3", "-2", "-1"};
    t_link_t *current = char_to_int_ll(6, params);
    cr_assert_eq(5, current->value);
    cr_assert_eq(4, current->next->value);
    cr_assert_eq(-3, current->next->next->value);
    cr_assert_eq(-2, current->next->next->next->value);
    cr_assert_eq(-1, current->next->next->next->next->value);
}

Test(char_to_int_ll, empty_list, .timeout=1)
{
    char *params[1] = {"exe"};
    t_link_t *current = char_to_int_ll(1, params);
    cr_assert_eq(current, NULL);
}