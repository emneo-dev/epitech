/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02M-alexandre.flion
** File description:
** div
*/

#include <stddef.h>

#include "castmania.h"

int integer_div(int a, int b)
{
    if (!b)
        return 0;
    return a / b;
}

float decimale_div(int a, int b)
{
    if (!b)
        return 0.0;
    return (float) a / (float) b;
}

void exec_div(division_t *operation)
{
    integer_op_t *tmp_int_op = NULL;
    decimale_op_t *tmp_dec_op = NULL;

    if (operation->div_type == INTEGER) {
        tmp_int_op = ((integer_op_t *) operation->div_op);
        tmp_int_op->res = integer_div(tmp_int_op->a, tmp_int_op->b);
        return;
    }
    tmp_dec_op = ((decimale_op_t *) operation->div_op);
    tmp_dec_op->res = decimale_div(tmp_dec_op->a, tmp_dec_op->b);
}