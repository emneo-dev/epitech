/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD03-alexandre.flion
** File description:
** substr
*/

#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#include "string.h"

string_t *substr(const string_t *this, int offset, int length)
{
    int32_t len = abs(length);
    char *buf = malloc(sizeof(char) * (len + 1));
    string_t *string = malloc(sizeof(string_t));

    offset += (offset < 0) ? this->size(this) : 0;
    offset -= (length < 0) ? len : 0;
    if (offset < 0) {
        len += offset;
        offset = 0;
    }
    if (len < 0 || offset > this->size(this))
        return NULL;
    strncpy(buf, this->str + offset, len);
    buf[len] = '\0';
    string_init(string, buf);
    free(buf);
    return string;
}