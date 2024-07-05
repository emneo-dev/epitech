/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019 [WSL: Debian]
** File description:
** handle_input
*/

#include <stdlib.h>
#include "sh.h"

result_t handle_input(char *cmd, env_t **ep)
{
    result_t base_result = {0, 0};

    if (!cmd) {
        base_result.do_exit = 1;
        return (base_result);
    }
    if (is_a_builtin(cmd))
        return (handle_builtin(cmd, ep));
    else
        return (handle_cmd(cmd, *ep));
    return (base_result);
}