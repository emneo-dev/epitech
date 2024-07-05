/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD03-alexandre.flion
** File description:
** split
*/

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "string.h"

char **split_c(const string_t *this, char separator)
{
    return my_str_split(this->str, separator);
}

string_t **split_s(const string_t *this, char separator)
{
    char **old_result = split_c(this, separator);
    char *tmp = NULL;

    for (int i = 0; old_result[i]; i++) {
        tmp = old_result[i];
        old_result[i] = malloc(sizeof(string_t));
        string_init((string_t *) (old_result[i]), tmp);
        free(tmp);
    }
    return (string_t **) (old_result);
}
