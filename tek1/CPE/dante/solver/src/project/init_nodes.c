/*
** EPITECH PROJECT, 2020
** CPE_dante
** File description:
** Initialize the nodes for Dijkstra
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "struct.h"

#pragma GCC diagnostic ignored "-Woverflow"
size_t *init_nodes(maze_t const *maze)
{
    size_t *nodes = NULL;

    nodes = malloc(sizeof(size_t) * (maze->size + maze->height + 1));
    if (!nodes) {
        dprintf(2, "\e[1;31m[FATAL]\e[0m: Failed to init nodes\n");
        return (NULL);
    }
    for (size_t i = 0; i < maze->size + maze->height + 1; i++)
        nodes[i] = -1;
    nodes[0] = 0;
    return (nodes);
}