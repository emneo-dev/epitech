/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_strcpy
*/

char *my_strcpy_arr(char *dest, char const *src)
{
    for (int i = 0; src[i] && src[i] != ' ' && src[i] != '\n'; ++i)
        dest[i] = src[i];
    return (dest);
}