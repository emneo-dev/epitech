/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int i = 0;

    if (!str)
        return (0);
    for (i = 0; str[i]; ++i);
    return (i);
}
