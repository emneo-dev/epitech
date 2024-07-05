/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Print a string with the non-printable characters in hex
*/

#include <my.h>

static void print_non_printable(char a)
{
    my_putchar('\\');
    char hex_dump[2];
    int n = (int) a;

    for (int i = 1; i >= 0; i--) {
        int tmp = n % 16;
        if (tmp == 0)
            hex_dump[i] = '0';
        else if (tmp < 10)
            hex_dump[i] = (char) (tmp + 48);
        else
            hex_dump[i] = (char) (tmp + 87);
        n = (n - tmp) / 16;
    }
    my_putchar((char) (hex_dump[0]));
    my_putchar((char) (hex_dump[1]));
}

int my_showstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32)
            print_non_printable(str[i]);
        else
            my_putchar(str[i]);
    }
    return (0);
}
