/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD03-alexandre.flion
** File description:
** compare
*/

#include <string.h>

#include "string.h"

int compare_s(const string_t *this, const string_t *str)
{
    return strcmp(this->str, str->str);
}

int compare_c(const string_t *this, const char *str)
{
    return strcmp(this->str, str);
}