/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019 [WSL: Ubuntu]
** File description:
** test_is_sorted
*/

#include <criterion/criterion.h>
#include "pushswap.h"

Test(is_sorted, sorted_3_nodes, .timeout=1)
{
    t_link_t a_1 = {3, NULL};
    t_link_t a_2 = {2, &a_1};
    t_link_t a_3 = {1, &a_2};
    t_link_t *a_head = &a_3;
    int tmp = is_sorted(a_head);
    cr_assert_eq(tmp, 1);
}

Test(is_sorted, not_sorted_3_nodes, .timeout=1)
{
    t_link_t a_1 = {1, NULL};
    t_link_t a_2 = {2, &a_1};
    t_link_t a_3 = {3, &a_2};
    t_link_t *a_head = &a_3;
    int tmp = is_sorted(a_head);
    cr_assert_eq(tmp, 0);
}

Test(is_sorted, NULL_test, .timeout=1)
{
    int tmp = is_sorted(NULL);
    cr_assert_eq(tmp, 1);
}