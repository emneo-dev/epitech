/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** get_splited_path
*/

#include "my.h"
#include "sh.h"

static char *get_path(char **envp)
{
    for (int i = 0; envp[i]; i++)
        if (!my_strncmp("PATH=", envp[i], 5))
            return (envp[i]);
    return (NULL);
}

char **get_splited_path(char **envp)
{
    char *path = NULL;

    if (!envp)
        return (NULL);
    path = get_path(envp);
    if (!path)
        return (NULL);
    return (my_str_split(path + 5, ':'));
}