/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02M-alexandre.flion
** File description:
** mem_ptr
*/

#include <string.h>
#include <stdlib.h>

#include "mem_ptr.h"

void add_str(const char *str1, const char *str2, char **res)
{
    *res = strdup(str1);
    if (!realloc(*res, strlen(str1) + strlen(str2) + 1))
        return;
    strcpy(*res + strlen(str1), str2);
}

void add_str_struct(str_op_t *str_op)
{
    str_op->res = strdup(str_op->str1);
    if (!realloc(str_op->res, strlen(str_op->str1) + strlen(str_op->str2) + 1))
        return;
    strcpy(str_op->res + strlen(str_op->str1), str_op->str2);
}