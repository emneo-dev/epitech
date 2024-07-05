/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD03-alexandre.flion
** File description:
** size
*/

#include <string.h>

#include "string.h"

int size(const string_t *this)
{
    if (!this->str)
        return -1;
    return strlen(this->str);
}