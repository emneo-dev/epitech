/*
** EPITECH PROJECT, 2019
** CPool_finalstumper_2019
** File description:
** Return the lengths of the given buffer
*/

#include <stdlib.h>

int *get_length(char const *str)
{
    int *ret = malloc(sizeof(int) * 2);
    ret[0] = 0;
    ret[1] = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            (ret[1])++;
    for (int i = 0; str[i] != '\n'; i++, (ret[0])++);
    return (ret);
}


