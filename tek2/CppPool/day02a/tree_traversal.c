/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** tree_traversal
*/

#include <stdlib.h>

#include "generic_list.h"
#include "tree_traversal.h"

void tree_traversal(tree_t tree, container_t *container, dump_func_t dump_func)
{
    tree_node_t *current = tree;

    if (!tree)
        return;
    do {
        for (node_t *tmp = current->children; tmp; tmp = tmp->next)
            container->push_func(container->container, tmp->value);
        tree_node_dump(current, dump_func);
    } while ((current = container->pop_func(container->container)));
}