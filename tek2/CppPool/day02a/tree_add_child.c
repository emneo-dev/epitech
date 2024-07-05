/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** tree_add_child
*/

#include <stdlib.h>

#include "tree_traversal.h"

tree_node_t *tree_add_child(tree_node_t *tree_node, void *data)
{
    tree_node_t *new_tree_node = malloc(sizeof(tree_node_t));

    if (!new_tree_node)
        return NULL;
    new_tree_node->children = NULL;
    new_tree_node->data = data;
    new_tree_node->parent = tree_node;
    if (!list_add_elem_at_back(&(tree_node->children), new_tree_node))
        return NULL;
    return new_tree_node;
}