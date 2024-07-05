/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** Sort two strings
*/

#include <my.h>

static char **swap_str(char *s1, char *s2);

char **sort_nbr_str(char **str)
{
    char *s1 = str[0];
    char *s2 = str[1];
    if (s1[0] > s2[0])
        return (swap_str(s1, s2));
    else if (s1[0] == '+' && my_strcmp(s1, s2) < 0)
        return (swap_str(s1, s2));
    else if (s1[0] == '-' && my_strcmp(s1, s2) > 0)
        return (swap_str(s1, s2));
    return (str);
}

static char **swap_str(char *s1, char *s2)
{
    char *s1_n = malloc(sizeof(char) * my_strlen(s2) + 1);
    char *s2_n = malloc(sizeof(char) * my_strlen(s1) + 1);
    my_strcpy(s1_n, s2);
    my_strcpy(s2_n, s1);
    char **ret = malloc(sizeof(s1_n) * 2);
    ret[0] = s1_n;
    ret[1] = s2_n;
    return (ret);
}
