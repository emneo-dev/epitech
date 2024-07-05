/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD03-alexandre.flion [SSH: 192.168.0.19]
** File description:
** my_str_split
*/

#include <stdint.h>
#include <stdlib.h>

#include "string.h"

static int word_len(char *str, char sep)
{
    int i = 0;

    for (i = 0; str[i] && str[i] != sep; i++);
    return (i);
}

static int count_words(char *str, char sep)
{
    int words = 0;

    for (uint32_t i = 0; str[i]; i++)
        if (str[i] == sep)
            words++;
    return words + 1;
}

static int get_new_word(char **str, char **dest, char sep)
{
    int size_word = 0;

    size_word = word_len(*str, sep);
    *dest = malloc(sizeof(char) * (size_word + 1));
    if (!(*dest))
        return (-1);
    my_split_cpy(*dest, *str, sep);
    return (0);
}

char **my_str_split(char *str, char sep)
{
    char **word_array = NULL;
    int is_get_success = 0;
    char *original_str = str;

    if (!str)
        return (NULL);
    word_array = malloc(sizeof(char *) * (count_words(str, sep) + 1));
    if (!word_array)
        return (NULL);
    for (int i = 0; i < count_words(original_str, sep); ++i) {
        is_get_success = get_new_word(&str, word_array + i, sep);
        if (is_get_success == -1)
            return (NULL);
        str += word_len(str, sep) + 1;
    }
    word_array[count_words(original_str, sep)] = NULL;
    return (word_array);
}