/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** Return whether or not the number as an str given is negative
*/

int is_negative(char *str)
{
    if (str[0] == '-')
        return (1);
    return (0);
}
