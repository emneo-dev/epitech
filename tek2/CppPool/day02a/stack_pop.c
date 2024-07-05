/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** stack_pop
*/

#include "stack.h"

bool stack_pop(stack_t *stack_ptr)
{
    return list_del_elem_at_front(stack_ptr);
}