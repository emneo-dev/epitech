/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_str_isnum
*/

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9')
            return (1);
    return (0);
}