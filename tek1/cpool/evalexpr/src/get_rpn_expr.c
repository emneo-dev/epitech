/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** Convert an expression from an infix notation to RPN
*/

#include <expr.h>
#include <my.h>

expr_t *put_node_to_list(expr_t **current, char *token);

char *get_next_info(char **str);

void push_token(char *token, expr_t *current, expr_t *push_stack_to_output);

void push_number(char *nb, expr_t *current);

expr_t **push_stack_to_output(expr_t **output, expr_t **operator);

/*
    Main function to parse the infix notation in RPN
*/

expr_t **get_rpn_expr(char *str)
{
    expr_t *output = malloc(sizeof(expr_t));
    expr_t *operator = malloc(sizeof(expr_t));

    char *info = get_next_info(&str);
    while (info) {
        if (!(info[0] >= '0' && info[0] <= '9'))
            push_token(info, operator, output);
        else
            push_number(info, output);
        free(info);
        char *info = get_next_info(&str);
    }
    free(info);
    return (push_stack_to_output(&output, &operator));
}