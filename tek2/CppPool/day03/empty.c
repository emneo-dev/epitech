/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD03-alexandre.flion
** File description:
** empty
*/

#include "string.h"

int empty(const string_t *this)
{
    if (this->size(this) > 0)
        return 0;
    return 1;
}