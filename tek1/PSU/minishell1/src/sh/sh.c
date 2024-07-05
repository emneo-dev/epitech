/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019 [WSL: Debian]
** File description:
** sh
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "my.h"
#include "sh.h"

static void replace_carriage(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == '\n') {
            str[i] = '\0';
            return;
        }
}

void handle_sigint()
{
    write(1, "\n", 1);
    print_prompt();
}

int sh(char **ep)
{
    char *input = NULL;
    result_t cmd_ret = {0, 0};
    size_t read_size_line = 0;
    size_t is_read = 0;
    env_t *env = env_cpy(ep);

    signal(SIGINT, handle_sigint);
    do {
        print_prompt();
        is_read = getline(&input, &read_size_line, stdin);
        if (is_read != (size_t) (-1) && input[0] != '\n') {
            replace_carriage(input);
            cmd_ret = handle_input(input, &env);
        }
    } while (input && !cmd_ret.do_exit && is_read != (size_t) (-1));
    free(input);
    my_putstr("exit\n");
    destroy_env(env);
    return (cmd_ret.status);
}