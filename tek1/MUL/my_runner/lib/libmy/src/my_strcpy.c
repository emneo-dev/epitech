/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_strcpy
*/

char *my_strcpy(char *dest, char const *src)
{
    for (int i = 0; src[i]; ++i)
        dest[i] = src[i];
    return (dest);
}