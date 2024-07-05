/*
** EPITECH PROJECT, 2020
** CPE_solostumper_2_2019
** File description:
** Entry point of the program
*/

#include <unistd.h>
#include "rrostring.h"

static int get_words_len(char **word_array)
{
    int i = 0;

    for (i = 0; word_array[i]; i++);
    return (i);
}

static int display_words(char **word_array)
{
    int len_arr = 0;

    len_arr = get_words_len(word_array);
    if (len_arr == 1)
        my_putstr(word_array[0]);
    else {
        my_putstr(word_array[len_arr - 1]);
        for (int i = 0; i < len_arr - 1; i++) {
            write(1, " ", 1);
            my_putstr(word_array[i]);
        }
    }
    write(1, "\n", 1);
    return (0);
}

int rrostring(int argc, char **argv)
{
    char **word_array = NULL;

    if (argc == 1) {
        write(1, "\n", 1);
        return (0);
    }
    else if (argc > 2)
        return (84);
    word_array = str_to_word_array(argv[1]);
    if (!word_array)
        return (84);
    return (display_words(word_array));
}
