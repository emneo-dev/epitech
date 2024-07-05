/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD03-alexandre.flion
** File description:
** assign
*/

#include <string.h>
#include <stdlib.h>

#include "string.h"

void assign_s(string_t *this, const string_t *str)
{
    this->str = realloc(this->str, strlen(str->str) + 1);
    strcpy(this->str, str->str);
}

void assign_c(string_t *this, const char *s)
{
    this->str = realloc(this->str, strlen(s) + 1);
    strcpy(this->str, s);
}