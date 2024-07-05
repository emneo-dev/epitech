/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** get_next_info
*/

#include <expr.h>
#include <my.h>

char *get_next_info(char **str)
{
    char *ret = malloc(sizeof(char) * my_strlen(*str));
    int i;
    if ((*str)[0] <= '9' && (*str)[0] >= '0') {
        for (i = 0; (*str)[0] <= '9' && (*str)[0] >= '0'; (*str)++, i++)
            ret[i] = (*str)[0];
        return (ret);
    }
    my_strncpy(ret, *str, 1);
    (*str)++;
    return (ret);
}
