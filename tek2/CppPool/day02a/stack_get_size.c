/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** stack_get_size
*/

#include "stack.h"

unsigned int stack_get_size(stack_t stack)
{
    return list_get_size(stack);
}