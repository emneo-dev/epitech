/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019 [WSL: Debian]
** File description:
** sh_cd
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "sh.h"

static result_t change_dir(char *directory, env_t **envp)
{
    char *path = NULL;

    if (access(directory, F_OK) == -1) {
        my_putstr(directory);
        my_putstr(": No such file or directory.\n");
        return ((result_t) {0, 0});
    }
    path = append("setenv OLDPWD ", getcwd(NULL, (size_t) NULL));
    sh_setenv(path, envp);
    chdir(directory);
    path = append("setenv PWD ", getcwd(NULL, (size_t) NULL));
    sh_setenv(path, envp);
    return ((result_t) {0, 0});
}

result_t sh_cd(char *cmd, env_t **ep)
{
    char **cmd_arr = NULL;
    int cmd_arr_len = 0;

    cmd_arr = my_str_to_word_array(cmd);
    for (cmd_arr_len = 0; cmd_arr[cmd_arr_len]; cmd_arr_len++);
    if (cmd_arr_len == 2)
        return (change_dir(cmd_arr[1], ep));
    return ((result_t) {0, 0});
}