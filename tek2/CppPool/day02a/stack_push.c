/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** stack_push
*/

#include "stack.h"

bool stack_push(stack_t *stack_ptr, void *elem)
{
    return list_add_elem_at_front(stack_ptr, elem);
}