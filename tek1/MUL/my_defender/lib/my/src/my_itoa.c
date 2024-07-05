/*
** EPITECH PROJECT, 2018
** origin
** File description:
** my_tools.c
*/

#include <stdlib.h>

static int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

char *reverse_array(char *str)
{
    int i = 0;
    int j = my_strlen(str) - 1;
    char *rev = malloc(sizeof(char) * my_strlen(str) + 1);

    while (j != -1) {
        rev[i] = str[j];
        j--;
        i++;
    }
    rev[i] = '\0';
    free(str);
    return (rev);
}

char *my_itoa(int nb)
{
    char *str = malloc(sizeof(char) * 100);
    int i = 0;

    while (nb > 9) {
        str[i] = nb % 10 + 48;
        nb = nb / 10;
        i++;
    }
    str[i] = nb % 10 + 48;
    str[i + 1] = '\0';
    str = reverse_array(str);
    return (str);
}