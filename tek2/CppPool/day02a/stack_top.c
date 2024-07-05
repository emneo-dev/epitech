/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** stack_top
*/

#include "stack.h"

void *stack_top(stack_t stack)
{
    return list_get_elem_at_front(stack);
}