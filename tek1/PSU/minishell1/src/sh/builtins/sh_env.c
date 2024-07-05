/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019 [WSL: Debian]
** File description:
** sh_env
*/

#include <unistd.h>
#include "my.h"
#include "sh.h"

result_t sh_env(char *cmd, env_t **envp)
{
    result_t base_result = {0, 0};
    env_t *ep = *envp;

    (void)cmd;
    for (; ep; ep = ep->next) {
        my_putstr(ep->data);
        write(1, "\n", 1);
    }
    return (base_result);
}