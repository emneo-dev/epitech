/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** Some desc
*/

int my_strlen(char const *str);
#include <stdlib.h>

char *my_strdup(char const *src)
{
    int length = my_strlen(src);
    char *str = malloc(sizeof(char) * length);

    for (int i = 0; i <= length; i++)
        str[i] = src[i];
    return (str);
}