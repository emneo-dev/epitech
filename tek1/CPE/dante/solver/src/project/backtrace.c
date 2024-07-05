/*
** EPITECH PROJECT, 2020
** solver
** File description:
** backtrace
*/

#include "struct.h"

static size_t get_smaller_second(size_t *nodes, maze_t *maze, size_t index)
{
    size_t current = nodes[index];

    if (index > maze->width && nodes[index - maze->width - 1] == current - 1 &&
        maze->buffer[index - maze->width - 1] == '*')
        return (index - maze->width - 1);
    else
        return (index + maze->width + 1);
}

static size_t get_smaller(size_t *nodes, maze_t *maze, size_t index)
{
    size_t current = nodes[index];

    if (nodes[index - 1] == current - 1 && maze->buffer[index - 1] == '*')
        return (index - 1);
    else if (nodes[index + 1] == current - 1 && maze->buffer[index + 1] == '*')
        return (index + 1);
    return (get_smaller_second(nodes, maze, index));
}

void backtrace(size_t *nodes, maze_t *maze)
{
    size_t current_index = maze->size - 1;

    maze->buffer[current_index] = 'o';
    while (maze->buffer[0] != 'o') {
        current_index = get_smaller(nodes, maze, current_index);
        maze->buffer[current_index] = 'o';
    }
}