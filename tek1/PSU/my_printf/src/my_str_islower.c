/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Return whether or not the given string is in lowercase
*/

int my_str_islower(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < 'a' || str[i] > 'z')
            return (0);
    return (1);
}