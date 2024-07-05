/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD03-alexandre.flion
** File description:
** string_init
*/

#include <string.h>

#include "string.h"

static const void *FUNCTION_POINTERS[23] = {
    assign_s,
    assign_c,
    append_s,
    append_c,
    at,
    clear,
    size,
    compare_s,
    compare_c,
    copy,
    c_str,
    empty,
    find_s,
    find_c,
    insert_c,
    insert_s,
    to_int,
    split_s,
    split_c,
    print,
    join_c,
    join_s,
    substr
};

void string_init(string_t *this, const char *s)
{
    if (!this || !s)
        return;
    this->str = strdup(s);
    memcpy(&(this->assign_s), FUNCTION_POINTERS, sizeof(FUNCTION_POINTERS));
}