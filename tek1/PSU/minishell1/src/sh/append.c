/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** append
*/

#include <stdlib.h>
#include "my.h"

char *append(char *first, char *second)
{
    char *new_str = NULL;

    new_str = malloc(sizeof(char) * (my_strlen(first) + my_strlen(second) + 1));
    if (!new_str)
        return (NULL);
    my_strcpy(new_str, first);
    my_strcpy(new_str + my_strlen(first), second);
    return (new_str);
}