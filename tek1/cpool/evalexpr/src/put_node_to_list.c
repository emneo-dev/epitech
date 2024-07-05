/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** Convert an expression from an infix notation to RPN
*/

#include <expr.h>
#include <my.h>

/*
    Put info in a node and add it to a previously created linked_list
*/

expr_t *put_node_to_list(expr_t **current, char *token)
{
    expr_t *node = malloc(sizeof(expr_t));
    node->str = malloc(sizeof(char) * my_strlen(token));
    my_strcpy(node->str, token);
    node->next = *current;
    *current = node;
    return (node);
}