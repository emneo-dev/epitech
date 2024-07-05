/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** env_cpy
*/

#include <stdlib.h>
#include "my.h"
#include "sh.h"

static int add_node(env_t **previous, char *data)
{
    env_t *new = NULL;

    new = malloc(sizeof(env_t));
    if (!new)
        return (1);
    new->data = malloc(sizeof(char) * (my_strlen(data) + 1));
    if (!new->data) {
        free(new);
        return (1);
    }
    my_strcpy(new->data, data);
    new->next = *previous;
    *previous = new;
    return (0);
}

void destroy_env(env_t *env)
{
    env_t *next = NULL;

    while (env) {
        free(env->data);
        next = env->next;
        free(env);
        env = next;
    }
}

char **env_ll_to_array(env_t *ep)
{
    char **new_ep = NULL;
    int i = 0;

    new_ep = malloc(sizeof(char *) * (my_ll_len(ep) + 1));
    if (!new_ep)
        return (NULL);
    for (i = 0; ep; ep = ep->next, i++) {
        new_ep[i] = malloc(sizeof(char) * (my_strlen(ep->data) + 1));
        if (!new_ep[i])
            return (NULL);
        my_strcpy(new_ep[i], ep->data);
    }
    new_ep[i] = NULL;
    return (new_ep);
}

env_t *env_cpy(char **envp)
{
    env_t *new_env = NULL;

    if (!envp)
        return (NULL);
    for (int i = 0; envp[i]; i++)
        if (add_node(&new_env, envp[i]))
            return (NULL);
    return (new_env);
}