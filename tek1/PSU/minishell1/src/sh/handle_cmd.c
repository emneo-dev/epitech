/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019 [WSL: Debian]
** File description:
** handle_cmd
*/

#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "sh.h"

static void destroy_word_array(char **arr)
{
    for (int i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
}

static result_t local_exec(char **cmd_arr, char **envp)
{
    if (access(cmd_arr[0], F_OK) == -1) {
        my_putstr(cmd_arr[0]);
        my_putstr(": Command not found.\n");
        return ((result_t) {0, 0});
    }
    if (access(cmd_arr[0], X_OK) == -1) {
        my_putstr(cmd_arr[0]);
        my_putstr(": Permission denied.\n");
        return ((result_t) {0, 0});
    }
    return (my_exec(cmd_arr, envp));
}

result_t handle_cmd(char *cmd, env_t *ep)
{
    result_t base_result = {0, 0};
    char **cmd_arr = NULL;
    char **envp = NULL;

    cmd_arr = my_str_to_word_array(cmd);
    envp = env_ll_to_array(ep);
    if (!cmd_arr || !envp)
        return ((result_t) {1, 84});
    if (!my_strncmp(cmd, "./", 2) || !my_strncmp(cmd, "/", 1) ||
        !my_strncmp(cmd, "../", 3))
        base_result = local_exec(cmd_arr, envp);
    else
        base_result = path_exec(cmd_arr, envp);
    destroy_word_array(cmd_arr);
    destroy_word_array(envp);
    return (base_result);
}