/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_strdup
*/

#include "my.h"

char *my_strdup(char const *src)
{
    int length = my_strlen(src);
    char *str = malloc(sizeof(char) * (length + 1));
    int i = 0;

    for (i = 0; i <= length; i++)
        str[i] = src[i];
    str[i] = '\0';
    return (str);
}
