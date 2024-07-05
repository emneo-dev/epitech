/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD03-alexandre.flion
** File description:
** append
*/

#include <string.h>
#include <stdlib.h>

#include "string.h"

void append_s(string_t *this, const string_t *map)
{
    this->str = realloc(this->str, strlen(map->str) + strlen(this->str) + 1);
    strcpy(this->str + strlen(this->str), map->str);
}

void append_c(string_t *this, const char *ap)
{
    this->str = realloc(this->str, strlen(ap) + strlen(this->str) + 1);
    strcpy(this->str + strlen(this->str), ap);
}