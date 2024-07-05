/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** stack_is_empty
*/

#include "stack.h"

bool stack_is_empty(stack_t stack)
{
    return list_is_empty(stack);
}