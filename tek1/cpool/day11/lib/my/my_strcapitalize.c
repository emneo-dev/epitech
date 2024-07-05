/*
** EPITECH PROJECT, 2019
** my_strcapitalize
** File description:
** Some desc
*/

char *my_strcapitalize(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (((str[i - 1] > 'Z' && str[i - 1] < 'a')
            || str[i - 1] > 'z' || str[i - 1] < 'A')
            && str[i] <= 'z' && str[i] >= 'a')
            str[i] -= 32;
        else if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
    return (str);
}
