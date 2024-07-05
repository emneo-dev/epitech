/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Return whether or not the given str only contains alpha-numerical caracters
*/

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (!((str[i] <= 'Z' && str[i] >= 'A')
            || (str[i] <= 'z' && str[i] >= 'a')))
            return (0);
    return (1);
}
