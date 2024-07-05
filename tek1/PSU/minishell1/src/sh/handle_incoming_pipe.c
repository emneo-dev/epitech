/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** handle_incoming_pipe
*/

#include <stdlib.h>
#include <stdio.h>
#include "sh.h"

static void replace_carriage(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == '\n') {
            str[i] = '\0';
            return;
        }
}

int handle_incoming_pipe(char **ep)
{
    char *input = NULL;
    result_t cmd_ret = {0, 0};
    size_t read_size_line = 0;
    size_t is_read = 0;
    env_t *env = env_cpy(ep);

    getline(&input, &read_size_line, stdin);
    if (is_read != (size_t) (-1)) {
        replace_carriage(input);
        cmd_ret = handle_input(input, &env);
    }
    free(input);
    destroy_env(env);
    return (cmd_ret.status);
}