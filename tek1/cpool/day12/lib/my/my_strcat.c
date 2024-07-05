/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** Some desc
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int len = my_strlen(dest);
    char *ptr = dest + len;

    for (int i = 0; src[i] != '\0'; i++)
        ptr[i] = src[i];
    return (dest);
}