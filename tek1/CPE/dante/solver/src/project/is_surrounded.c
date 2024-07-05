/*
** EPITECH PROJECT, 2020
** solver
** File description:
** is_surrounded
*/

#include <stdio.h>
#include "struct.h"

int can_go(size_t *nodes, maze_t *maze, size_t index)
{
    return (nodes[index] == (size_t) -1 && maze->buffer[index] != 'X' &&
            maze->buffer[index] != '\n');
}

int is_surrounded(size_t *nodes, maze_t *maze, size_t index)
{
    if (index == 0)
        return ((!can_go(nodes, maze, 1) &&
        !can_go(nodes, maze, maze->width + 1)));
    else if (index < maze->width)
        return ((!can_go(nodes, maze, index + 1) &&
        !can_go(nodes, maze, index + maze->width + 1)
        && !can_go(nodes, maze, index - 1)));
    else if (index > maze->size - maze->width)
        return (((!can_go(nodes, maze, index + 1) &&
        !can_go(nodes, maze, index - maze->width - 1)
        && !can_go(nodes, maze, index - 1))));
    return ((!can_go(nodes, maze, index + 1) &&
        !can_go(nodes, maze, index + maze->width + 1)
        && !can_go(nodes, maze, index - 1) &&
        !can_go(nodes, maze, index - maze->width - 1)));
}