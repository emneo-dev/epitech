/*
** EPITECH PROJECT, 2019
** my_print_alpha.c
** File description:
** print the alphabet in ascending order
*/

#include <stdlib.h>
#include "my.h"

static char *reverse_array(char *str)
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

char *my_ulltos(unsigned long long nb)
{
    char *str = malloc(sizeof(char) * 21);
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