/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD03-alexandre.flion
** File description:
** at
*/

#include <string.h>

#include "string.h"

char at(const string_t *this, size_t pos)
{
    if (pos >= strlen(this->str))
        return -1;
    return this->str[pos];
}