/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD03-alexandre.flion
** File description:
** copy
*/

#include <string.h>

#include "string.h"

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    if (n > strlen(this->str + pos))
        return strlen(strncpy(s, this->str + pos, n)) + 1;
    strncpy(s, this->str + pos, n);
    return n;
}