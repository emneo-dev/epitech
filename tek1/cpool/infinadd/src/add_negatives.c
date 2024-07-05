/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** Main file for the infinadd project
*/

#include <my.h>
#include <stdlib.h>

static int add_negatives_sub(char *result, char *s1, char *s2);

static int get_longest_len(char const *s1, char const *s2);

int add_negatives(char *s1, char *s2)
{
    char *result = malloc(sizeof(char) * (get_longest_len(s1, s2) + 2));
    for (int i = 0; i < get_longest_len(s1 + 1, s2 + 1); i++)
        result[i] = '0';
    add_negatives_sub(result, s1 + 1, s2 + 1);
    my_putchar('-');
    if (*(result - 1) == '1')
        my_putstr(result - 1);
    else
        my_putstr(result);
    return (0);
}

static int add_negatives_sub(char *result, char *s1, char *s2)
{
    char *s1_reader = s1 + my_strlen(s1) - 1;
    char *s2_reader = s2 + my_strlen(s2) - 1;
    int tmp = 0;
    int ret = 0;
    char *zero = malloc(sizeof(char));
    *zero = '0';
    result[my_strlen(result)] = '\0';

    for (int i = my_strlen(result) - 1; tmp <= get_longest_len(s1, s2) + 1; i--) {
        if (s1_reader[0] + s2_reader[0] - 96 + ret > 9) {
            result[i] = s1_reader[0] + s2_reader[0] + ret - 58;
            ret = 1;
        }
        else {
            result[i] = s1_reader[0] + s2_reader[0] + ret - 48;
            ret = 0;
        }
        tmp++;
        s1_reader = s1_reader == s1 || s1_reader == zero ? zero : s1_reader - 1;
        s2_reader = s2_reader == s2 || s2_reader == zero ? zero : s2_reader - 1;
    }
}

static int get_longest_len(char const *s1, char const *s2)
{
    int ret = my_strlen(s1) < my_strlen(s2) ? my_strlen(s2) : my_strlen(s1);
    return (ret);
}
