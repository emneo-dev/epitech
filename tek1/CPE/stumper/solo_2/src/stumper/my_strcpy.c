/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_strcpy
*/

void my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (i = 0; src[i] != '\t' && src[i] != ' ' && src[i]; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
}
