/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019 [WSL: Ubuntu]
** File description:
** test_push_a_to_b
*/

#include <criterion/criterion.h>
#include "pushswap.h"

Test(push_a_to_b, normal_3_nodes_each, .timeout=1)
{
    t_link_t a_1 = {1, NULL};
    t_link_t a_2 = {2, &a_1};
    t_link_t a_3 = {3, &a_2};
    t_link_t b_1 = {4, NULL};
    t_link_t b_2 = {5, &b_1};
    t_link_t b_3 = {6, &b_2};
    t_link_t *b_head = &b_3;
    t_link_t *a_head = &a_3;
    push_a_to_b(&a_head, &b_head);
    cr_assert_eq(a_head->value, 2);
    cr_assert_eq(b_head->value, 3);
}

Test(push_a_to_b, empty_list, .timeout=1)
{
    push_a_to_b(NULL, NULL);
}

Test(push_a_to_b, b_empty, .timeout=1)
{
    t_link_t a_1 = {1, NULL};
    t_link_t *b_head = NULL;
    t_link_t *a_head = &a_1;
    push_a_to_b(&a_head, &b_head);
    cr_assert_eq(a_head, NULL);
    cr_assert_eq(b_head->value, 1);
}

Test(push_a_to_b, a_empty, .timeout=1)
{
    t_link_t b_1 = {1, NULL};
    t_link_t *b_head = &b_1;
    t_link_t *a_head = NULL;
    push_a_to_b(&a_head, &b_head);
    cr_assert_eq(a_head, NULL);
    cr_assert_eq(b_head->value, 1);
}