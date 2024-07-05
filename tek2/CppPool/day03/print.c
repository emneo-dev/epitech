/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD03-alexandre.flion
** File description:
** print
*/

#include <unistd.h>

#include "string.h"

void print(const string_t *this)
{
    write(1, this->str, this->size(this));
}