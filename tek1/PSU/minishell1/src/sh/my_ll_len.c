/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_ll_len
*/

#include "sh.h"

int my_ll_len(env_t *env)
{
    int i = 0;

    for (i = 0; env; env = env->next, i++);
    return (i);
}