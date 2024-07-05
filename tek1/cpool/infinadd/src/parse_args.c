/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** Parses the arguments given to the program
*/

#include <my.h>

static char *get_nbr_sign(char *str);

static void get_nbr_str(int i, int sign, char *str, char *result);

char **parse_args(char *s1, char *s2)
{
    char *s1_n = malloc(sizeof(char) * my_strlen(s1) + 1);
    char *s2_n = malloc(sizeof(char) * my_strlen(s2) + 1);
    s1_n = get_nbr_sign(s1);
    s2_n = get_nbr_sign(s2);
    char **ret = malloc(sizeof(s1_n) * 2);
    ret[0] = s1_n;
    ret[1] = s2_n;
    return (ret);
}

static char *get_nbr_sign(char *str)
{
    int zz = 0;
    char *result = malloc(sizeof(char) * my_strlen(str) + 1);
    int sign = 1;

    for (int i = 0; str[i] != '\0' && zz == 0; i++) {
        if (str[i] == '-')
            sign *= -1;
        else if (str[i] >= '0' && str[i] <= '9') {
            zz = 1;
            get_nbr_str(i, sign, str, result);
        }
    }
    return (result);
}

static void get_nbr_str(int i, int sign, char *str, char *result)
{
    for (int z = 1; str[i] != '\0' && str[i] >= '0' && str[i] <= '9'; z++, i++)
        result[z] = str[i];
    result[0] = sign == -1 ? '-' : '+';
}
