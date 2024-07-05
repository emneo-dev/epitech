/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Reverse the characters of a string
*/

#include <my.h>

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    int half_len;
    int i;
    char tmp;

    half_len = (len % 2 == 0) ? len / 2 : len / 2 + 0.5;
    for (i = 0; i <= half_len - 1; i++) {
        tmp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = tmp;
    }
    return (str);
}
