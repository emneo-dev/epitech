/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** Convert an expression from an infix notation to RPN
*/

#include <expr.h>
#include <my.h>

expr_t *put_node_to_list(expr_t **current, char *token);

expr_t **push_stack_to_output(expr_t **output, expr_t **operator)
{
    for (int i = 0; (*operator)->next != 0; (*operator) = (*operator)->next)
        put_node_to_list(output, (*operator)->str);
    put_node_to_list(output, (*operator)->str);
    return (output);
}