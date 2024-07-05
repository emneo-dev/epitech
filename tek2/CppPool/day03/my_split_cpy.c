/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD03-alexandre.flion
** File description:
** my_split_cpy
*/

char *my_split_cpy(char *dest, char const *src, char sep)
{
    int i = 0;

    for (i = 0; src[i] && src[i] != sep; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}