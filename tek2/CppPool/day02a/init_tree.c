/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** init_tree
*/

#include <stdlib.h>

#include "tree_traversal.h"

bool init_tree(tree_t *tree_ptr, void *data)
{
    *tree_ptr = malloc(sizeof(tree_node_t));

    if (!(*tree_ptr))
        return false;
    (*tree_ptr)->children = NULL;
    (*tree_ptr)->data = data;
    (*tree_ptr)->parent = NULL;
    return true;
}