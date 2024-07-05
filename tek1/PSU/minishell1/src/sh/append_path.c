/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** append_path
*/

#include <stdlib.h>
#include "my.h"

char *append_path(char *first, char *second)
{
    char *new_str = NULL;

    new_str = malloc(sizeof(char) * (my_strlen(first) + my_strlen(second) + 2));
    if (!new_str)
        return (NULL);
    my_strcpy(new_str, first);
    new_str[my_strlen(first)] = '/';
    my_strcpy(new_str + my_strlen(first) + 1, second);
    return (new_str);
}