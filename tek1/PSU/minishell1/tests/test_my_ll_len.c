/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** test_my_ll_len
*/

#include <criterion/criterion.h>
#include "sh.h"

Test(my_ll_len, len_3, .timeout = 1)
{
    env_t *first = NULL;
    env_t *second = NULL;
    env_t *third = NULL;
    int ll_len = 0;

    first = malloc(sizeof(env_t));
    second = malloc(sizeof(env_t));
    third = malloc(sizeof(env_t));
    if (!first || !second || !third)
        cr_assert_fail();
    first->next = second;
    second->next = third;
    third->next = NULL;
    ll_len = my_ll_len(first);
    cr_expect_eq(ll_len, 3);
}