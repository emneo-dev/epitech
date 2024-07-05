/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** Some desc
*/

#include <stdlib.h>

static int count_words(char const *str);

static int is_alpha(char a);

static int get_new_words(char const *str, int wc, char **tab);

char **my_str_to_word_array(char const *str)
{
    int wc = count_words(str);
    char **tab = malloc(sizeof(char*) * (wc + 1));
    for (int i = 0; i < wc + 1; i++)
        tab[i] = malloc(sizeof(char) * 100);
    get_new_words(str, wc, tab);
    tab[wc] = 0;
    return (tab);
}

static int get_new_words(char const *str, int wc, char **tab)
{
    int tab_index = 0;
    int sub_tab_index = 0;
    int new_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_alpha(str[i]) == 0 && new_word == 1) {
            new_word = 0;
            sub_tab_index = 0;
            tab_index++;
        }
        else if (is_alpha(str[i]) == 1) {
            new_word = 1;
            tab[tab_index][sub_tab_index] = str[i];
            sub_tab_index++;
        }
    }
    return (0);
}

static int count_words(char const *str)
{
    int words = 0;
    int new_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_alpha(str[i]) == 0 && new_word == 1)
            new_word = 0;
        else if (is_alpha(str[i]) == 1 && new_word == 0) {
            new_word = 1;
            words++;
        }
    }
    return (words);
}

static int is_alpha(char a)
{
    if ((a <= 'Z' && a >= 'A')
        || (a <= 'z' && a >= 'a')
        || (a <= '9' && a >= '0'))
        return (1);
    else
        return (0);
}
