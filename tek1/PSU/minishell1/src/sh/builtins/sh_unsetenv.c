/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019 [WSL: Debian]
** File description:
** sh_unsetenv
*/

#include <stdlib.h>
#include "my.h"
#include "sh.h"

static result_t error_handling(void)
{
    my_putstr("unsetenv: Too few arguments.\n");
    return ((result_t) {0, 0});
}

static void remove_node(env_t **ep, env_t *previous, env_t *original)
{
    env_t *next = NULL;

    if (!previous) {
        next = (*ep)->next;
        free((*ep)->data);
        free((*ep));
        *ep = next;
        return;
    }
    next = (*ep)->next;
    previous->next = next;
    free((*ep)->data);
    free(*ep);
    *ep = original;
}

static void remove_env(char *to_rm, env_t **ep)
{
    env_t *previous = NULL;
    env_t *original = *ep;

    while (*ep) {
        if (my_strcmp(to_rm, (*ep)->data) == -'=')
            return (remove_node(ep, previous, original));
        previous = *ep;
        *ep = (*ep)->next;
    }
    *ep = original;
}

result_t sh_unsetenv(char *cmd, env_t **ep)
{
    char **cmd_arr = NULL;
    int cmd_arr_len = 0;

    cmd_arr = my_str_to_word_array(cmd);
    for (cmd_arr_len = 0; cmd_arr[cmd_arr_len]; cmd_arr_len++);
    if (cmd_arr_len < 2)
        return (error_handling());
    for (int i = 1; cmd_arr[i]; i++)
        remove_env(cmd_arr[i], ep);
    return ((result_t) {0, 0});
}