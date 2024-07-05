/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int i;

    for (i = 0; str[i]; ++i);
    return (i);
}