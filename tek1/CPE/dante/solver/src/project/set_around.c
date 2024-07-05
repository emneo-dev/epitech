/*
** EPITECH PROJECT, 2020
** solver
** File description:
** set_around
*/

#include "prototype.h"
#include "struct.h"

static void set_top(size_t *nodes, maze_t *maze, size_t index)
{
    nodes[index + 1] = (can_go(nodes, maze, index + 1))
        ? nodes[index] + 1 : nodes[index + 1];
    nodes[index + maze->width + 1] =
        (can_go(nodes, maze, index + maze->width + 1))
        ? nodes[index] + 1 : nodes[index + maze->width + 1];
    nodes[index - 1] = (can_go(nodes, maze, index - 1))
        ? nodes[index] + 1 : nodes[index - 1];
}

static void set_middle(size_t *nodes, maze_t *maze, size_t index)
{
    nodes[index + 1] = (can_go(nodes, maze, index + 1)) ? nodes[index] + 1 :
        nodes[index + 1];
    nodes[index + maze->width + 1] =
        (can_go(nodes, maze, index + maze->width + 1)) ?
        nodes[index] + 1 : nodes[index + maze->width + 1];
    nodes[index - maze->width - 1] =
        (can_go(nodes, maze, index - maze->width - 1)) ?
        nodes[index] + 1 : nodes[index - maze->width - 1];
    nodes[index - 1] = (can_go(nodes, maze, index - 1)) ?
        nodes[index] + 1 : nodes[index - 1];
}

static void set_top_left(size_t *nodes, maze_t *maze)
{
    nodes[1] = (can_go(nodes, maze, 1)) ? 1 : nodes[1];
    nodes[maze->width + 1] = (can_go(nodes, maze, maze->width + 1))
        ? 1 : nodes[maze->width + 1];
}

static void set_bottom(size_t *nodes, maze_t *maze, size_t index)
{
    nodes[index + 1] = (can_go(nodes, maze, index + 1)) ?
        nodes[index] + 1 : nodes[index + 1];
    nodes[index - maze->width - 1] =
        (can_go(nodes, maze, index - maze->width - 1))
        ? nodes[index] + 1 : nodes[index - maze->width - 1];
    nodes[index - 1] = (can_go(nodes, maze, index - 1)) ?
        nodes[index] + 1 : nodes[index - 1];
}

void set_around(size_t *nodes, maze_t *maze, size_t index)
{
    if (index == 0)
        return (set_top_left(nodes, maze));
    else if (index < maze->width)
        return (set_top(nodes, maze, index));
    else if (index > maze->size - maze->width)
        return (set_bottom(nodes, maze, index));
    return (set_middle(nodes, maze, index));
}