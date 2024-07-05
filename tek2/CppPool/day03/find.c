/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD03-alexandre.flion
** File description:
** find
*/

#include <stdint.h>
#include <string.h>

#include "string.h"

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    char *found = NULL;

    if (this->size(this) == -1 || pos >= (uint32_t) this->size(this))
        return -1;
    if ((found = strstr(this->str + pos, str->str)))
        return found - this->str;
    return -1;
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    char *found = NULL;

    if (this->size(this) == -1 || pos >= (uint32_t) this->size(this))
        return -1;
    if ((found = strstr(this->str + pos, str)))
        return found - this->str;
    return -1;
}