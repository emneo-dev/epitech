/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** Convert an expression from an infix notation to RPN
*/

#include <expr.h>
#include <my.h>

expr_t *put_node_to_list(expr_t **current, char *token);

static void handle_paren(char *token, expr_t **current, expr_t **output)
{
    while ((*current)->str != "(") {
        put_node_to_list(output, (*current)->str);
        current = (*current)->next;
    }
    current = (*current)->next;
}

/*
    Push an operator on the stack
*/
<<<<<<< HEAD
void push_token(char *token, expr_t *current, expr_t *output) {
    if (token[0] == ')')
        handle_paren(token, &current, &output);
    else if (get_precedence(token[0]) <= get_precedence(current->str)
        && get_precedence(current->str) != 4 && get_precedence(token[0]) != 4) {
        put_node_to_list(&output, current->str);
        my_strcpy(current->str, token);
    } else
        put_node_to_list(&current, token);
=======

void push_token(char *token, expr_t *current) {
    put_node_to_list(&current, token);
>>>>>>> be1b4243203ca268b2364de093272808e0546b8b
}