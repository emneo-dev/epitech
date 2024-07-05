/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** Convert an expression from an infix notation to RPN
*/

#include <my.h>

int get_precedence(char token)
{
    if (token == '/' || token == '*' || token == '%')
        return (3);
    else if (token == '-' || token == '+')
        return (2);
    else if (token == ')' || token == '(')
        return (4);
    my_putstr("Something went wrong...");
    return (-1);
}