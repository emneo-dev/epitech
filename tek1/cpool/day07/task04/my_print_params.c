/*
** EPITECH PROJECT, 2019
** my_print_params
** File description:
** Some desc
*/

#include <my.h>

int main(int argc, char const *argv[])
{
    for (int i = 0; i < argc; i++) {
        my_putstr(argv[i]);
        my_putchar('\n');
    }
    return (0);
}