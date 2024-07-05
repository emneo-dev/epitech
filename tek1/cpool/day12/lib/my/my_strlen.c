/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** Some desc
*/

int my_putchar(char);

int my_strlen(char const *str)
{
    int i = 0;

    while (*str != '\0') {
        str++;
        i++;
    }
    return (i);
}
