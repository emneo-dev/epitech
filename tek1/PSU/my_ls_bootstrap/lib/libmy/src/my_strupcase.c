/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Puts every letter in uppercase
*/

char *my_strupcase(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
    return (str);
}
