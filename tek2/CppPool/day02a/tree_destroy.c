/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** tree_destroy
*/

#include <stdlib.h>

#include "tree_traversal.h"

bool tree_destroy(tree_t *tree_ptr)
{
    node_t *current = NULL;
    node_t *tmp = NULL;

    if (!(*tree_ptr))
        return false;
    current = (*tree_ptr)->children;
    while (current) {
        tmp = current->next;
        tree_destroy((tree_t *)(&(current->value)));
        free(current);
        current = tmp;
    }
    free(*tree_ptr);
    *tree_ptr = NULL;
    return true;
}