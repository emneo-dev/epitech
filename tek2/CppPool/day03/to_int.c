/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD03-alexandre.flion
** File description:
** to_int
*/

#include <stdlib.h>

#include "string.h"

int to_int(const string_t *this)
{
    return atoi(this->str);
}