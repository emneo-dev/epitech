/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** path_exec
*/

#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include "my.h"
#include "sh.h"

static int is_cmd_here(char *cmd, char *c_path)
{
    DIR *d = NULL;
    struct dirent *dir;

    d = opendir(c_path);
    if (!d)
        return (0);
    while ((dir = readdir(d)) != NULL)
        if (!my_strcmp(cmd, dir->d_name))
            return (1);
    closedir(d);
    return (0);
}

result_t path_exec(char **cmd_arr, char **envp)
{
    char **path = NULL;

    path = get_splited_path(envp);
    for (int i = 0; path && path[i]; i++)
        if (is_cmd_here(cmd_arr[0], path[i])) {
            cmd_arr[0] = append_path(path[i], cmd_arr[0]);
            return (my_exec(cmd_arr, envp));
        }
    my_putstr(cmd_arr[0]);
    my_putstr(": Command not found.\n");
    return ((result_t) {0, 0});
}