/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** Some desc
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int n)
{
    int len = my_strlen(dest);
    char *ptr = dest + len;

    for (int i = 0; src[i] != '\0' && i < n; i++)
        ptr[i] = src[i];
    return (dest);
}