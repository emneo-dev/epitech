/*
** EPITECH PROJECT, 2019
** my_show_param_array
** File description:
** Some desc
*/

#include <my.h>

int my_show_param_array(struct info_param const *par)
{
    int n = 0;

    while (par[n].length) {
        my_put_nbr(par[n].length);
        my_putchar('\n');
        my_putstr(par[n].str);
        my_putchar('\n');
        my_putstr(par[n].copy);
        my_putchar('\n');
        my_show_word_array(par[n].word_array);
        n++;
    }
    return (0);
}
