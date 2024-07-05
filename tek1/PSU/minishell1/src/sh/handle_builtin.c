/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019 [WSL: Debian]
** File description:
** handle_builtin
*/

#include "my.h"
#include "sh.h"

static const char *cmds[5] = {"cd", "env", "setenv", "unsetenv", "exit"};

static const int nb_cmds = 5;

static result_t (*cmd_arr[5])(char *, env_t **) = {sh_cd,
                                            sh_env,
                                            sh_setenv,
                                            sh_unsetenv,
                                            sh_exit};

result_t handle_builtin(char *cmd, env_t **ep)
{
    result_t base_result = {0, 0};

    for (int i = 0; i < nb_cmds; i++)
        if (!my_strncmp(cmd, cmds[i], get_cmd_len(cmd))
            && get_cmd_len(cmd) == my_strlen(cmds[i])) {
            return (cmd_arr[i](cmd, ep));
        }
    return (base_result);
}