/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD03-alexandre.flion
** File description:
** insert
*/

#include <string.h>
#include <stdlib.h>

#include "string.h"

void insert_c(string_t *this, size_t pos, const char *str)
{
    char *tmp_buf = NULL;

    if (pos >= (size_t) this->size(this))
        return append_c(this, str);
    this->str = realloc(this->str, strlen(this->str) + strlen(str) + 1);
    tmp_buf = strdup(pos + this->str);
    strcpy(pos + this->str, str);
    strcpy(strlen(str) + pos + this->str, tmp_buf);
    free(tmp_buf);
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    char *tmp_buf = NULL;

    if (pos >= (size_t) this->size(this))
        return append_s(this, str);
    this->str = realloc(this->str, strlen(this->str) + strlen(str->str) + 1);
    tmp_buf = strdup(pos + this->str);
    strcpy(pos + this->str, str->str);
    strcpy(strlen(str->str) + pos + this->str, tmp_buf);
    free(tmp_buf);
}