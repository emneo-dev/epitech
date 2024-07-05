/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD03-alexandre.flion
** File description:
** string_destroy
*/

#include <stdlib.h>

#include "string.h"

void string_destroy(string_t *this)
{
    free(this->str);
}