/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** Writes a string to the console
*/

int my_putchar(char);

int my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        str++;
    }
}
