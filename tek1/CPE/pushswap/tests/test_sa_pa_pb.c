/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019 [WSL: Ubuntu]
** File description:
** test_sa_pa_pb
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "pushswap.h"

Test(sa, sa_normal, .timeout=1)
{
    t_link_t a_1 = {1, NULL};
    t_link_t a_2 = {2, &a_1};
    sa(&a_2);
    cr_assert_eq(a_1.value, 2);
    cr_assert_eq(a_2.value, 1);
}

Test(sa, sa_with_NULL, .timeout=1)
{
    sa(NULL);
}

Test(sa, sa_one_value, .timeout=1)
{
    t_link_t a_1 = {1, NULL};
    sa(&a_1);
}

Test(pa, pa_normal, .timeout=1)
{
    t_link_t a_1 = {1, NULL};
    t_link_t a_2 = {2, &a_1};
    t_link_t a_3 = {3, &a_2};
    t_link_t b_1 = {4, NULL};
    t_link_t b_2 = {5, &b_1};
    t_link_t b_3 = {6, &b_2};
    t_link_t *b_head = &b_3;
    t_link_t *a_head = &a_3;
    pa(&a_head, &b_head);
    cr_assert_eq(a_head->value, 6);
    cr_assert_eq(b_head->value, 5);
}

Test(pb, pb_normal, .timeout=1)
{
    t_link_t a_1 = {1, NULL};
    t_link_t a_2 = {2, &a_1};
    t_link_t a_3 = {3, &a_2};
    t_link_t b_1 = {4, NULL};
    t_link_t b_2 = {5, &b_1};
    t_link_t b_3 = {6, &b_2};
    t_link_t *b_head = &b_3;
    t_link_t *a_head = &a_3;
    pb(&a_head, &b_head);
    cr_assert_eq(a_head->value, 2);
    cr_assert_eq(b_head->value, 3);
}