/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019 [WSL: Debian]
** File description:
** is_a_builtin
*/

#include "my.h"

static const char *cmds[5] = {"cd", "env", "setenv", "unsetenv", "exit"};

static const int nb_cmds = 5;

int get_cmd_len(char *cmd)
{
    int i = 0;

    for (i = 0; cmd[i] && cmd[i] != ' '; ++i);
    return (i);
}

int is_a_builtin(char *cmd)
{
    for (int i = 0; i < nb_cmds; i++)
        if (!my_strncmp(cmd, cmds[i], get_cmd_len(cmd))
            && get_cmd_len(cmd) == my_strlen(cmds[i]))
            return (1);
    return (0);
}