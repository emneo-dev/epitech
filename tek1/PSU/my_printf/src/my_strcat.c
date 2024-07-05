/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Concatenate two strings together
*/

#include <my.h>

char *my_strcat(char *dest, char const *src)
{
    char *ptr = dest + my_strlen(dest);

    for (int i = 0; src[i] != '\0'; i++)
        ptr[i] = src[i];
    return (dest);
}
