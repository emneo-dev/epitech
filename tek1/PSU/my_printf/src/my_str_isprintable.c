/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Return whether or not the given str only contains printable caracters
*/

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < 32)
            return (0);
    return (1);
}