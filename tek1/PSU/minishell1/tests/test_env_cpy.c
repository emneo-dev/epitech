/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** test_env_cpy
*/

#include <criterion/criterion.h>
#include "sh.h"

Test(env_cpy, nodes_3_env, .timeout=1)
{
    env_t *new_env = NULL;
    char **old_env = NULL;

    old_env = malloc(sizeof(char *) * 4);
    if (!old_env)
        cr_assert(0);
    old_env[0] = "first env";
    old_env[1] = "second env";
    old_env[2] = "third env";
    old_env[3] = NULL;
    new_env = env_cpy(old_env);
    cr_expect_str_eq(old_env[2], new_env->data);
    cr_expect_str_eq(old_env[1], new_env->next->data);
    cr_expect_str_eq(old_env[0], new_env->next->next->data);
}

Test(destroy_env, node_3_env, .timeout=1)
{
    env_t *new_env = NULL;
    char **old_env = NULL;

    old_env = malloc(sizeof(char *) * 4);
    if (!old_env)
        cr_assert(0);
    old_env[0] = "first env";
    old_env[1] = "second env";
    old_env[2] = "third env";
    old_env[3] = NULL;
    new_env = env_cpy(old_env);
    cr_expect_str_eq(old_env[2], new_env->data);
    cr_expect_str_eq(old_env[1], new_env->next->data);
    cr_expect_str_eq(old_env[0], new_env->next->next->data);
    destroy_env(new_env);
}