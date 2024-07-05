/*
** EPITECH PROJECT, 2019
** it put
** File description:
** a string on ur terminal.
*/

#include <unistd.h>

void my_putstr(char *str);

void my_putarray(char **array)
{
    int i = 0;

    while (array[i] != 0) {
        my_putstr(array[i]);
        write(1, "\n", 1);
        i++;
    }
}