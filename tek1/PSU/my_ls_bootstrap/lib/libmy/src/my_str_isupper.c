/*
** EPITECH PROJECT, 2019
** my_str_isupper
** File description:
** Return whether or not the given str only contains uppercase caracters
*/

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < 'A' || str[i] > 'Z')
            return (0);
    return (1);
}