/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** tree_node_dump
*/

#include "tree_traversal.h"

void tree_node_dump(tree_node_t *tree_node, dump_func_t dump_func)
{
    dump_func(tree_node->data);
}