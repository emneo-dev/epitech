/*
** EPITECH PROJECT, 2019
** my_str_isalpha
** File description:
** Some desc
*/

int my_str_isalpha(char const *str)
{
    int isAlpha = 1;
    int i = 0;

    while (str[i] != '\0') {
        if (!((str[i] <= 'Z' && str[i] >= 'A')
            || (str[i] <= 'z' && str[i] >= 'a')))
            isAlpha = 0;
        i++;
    }
    return (isAlpha);
}
