/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Show the strings contained in an array
*/

#include <my.h>

int my_show_word_array(char * const *tab)
{
    for (int i = 0; tab[i]; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return (0);
}
