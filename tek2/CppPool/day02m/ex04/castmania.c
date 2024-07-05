/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02M-alexandre.flion
** File description:
** castmania
*/

#include <stdio.h>

#include "castmania.h"

static void print_div(division_t *div)
{
    if (div->div_type == INTEGER)
        printf("%d\n", ((integer_op_t *) (div->div_op))->res);
    else
        printf("%f\n", ((decimale_op_t *) (div->div_op))->res);
}

void exec_operation(instruction_type_t instruction_type, void *data)
{
    if (instruction_type == ADD_OPERATION) {
        exec_add((addition_t *) (((instruction_t *) data)->operation));
        if (((instruction_t *) data)->output_type == VERBOSE)
            printf("%d\n",
            ((addition_t *) (((instruction_t *) data)->operation))->add_op.res);
    }
    else {
        exec_div((division_t *) (((instruction_t *) data)->operation));
        if (((instruction_t *) data)->output_type == VERBOSE)
            print_div((division_t *) (((instruction_t *) data)->operation));
    }
}

void exec_instruction(instruction_type_t instruction_type, void *data)
{
    if (instruction_type == PRINT_INT)
        printf("%d\n", *((int *) data));
    else if (instruction_type == PRINT_FLOAT)
        printf("%f\n", *((float *) data));
    else
        exec_operation(instruction_type, data);
}
