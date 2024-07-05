/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** Convert an expression from an infix notation to RPN
*/

#include <expr.h>
#include <my.h>

expr_t *put_node_to_list(expr_t **current, char *token);

/*
    Push a number on the output
*/

void push_number(char *nb, expr_t *current) {
    put_node_to_list(&current, nb);
}
