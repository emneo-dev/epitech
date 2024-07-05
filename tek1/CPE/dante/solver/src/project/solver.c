/*
** EPITECH PROJECT, 2020
** CPE_dante
** File description:
** Entry point for the solver
*/

#include <stdio.h>
#include <unistd.h>
#include "prototype.h"

static maze_t *load_maze(char const *filepath)
{
    maze_t *maze = NULL;

    maze = seek_n_read(filepath);
    if (!maze)
        dprintf(2, "\e[1;31m[FATAL]\e[0m: Failed to load the maze\n");
    set_maze_dimensions(maze);
    return (maze);
}

static size_t get_lowest_node(size_t *nodes, maze_t *maze)
{
    size_t lowest_index = -1;
    size_t lowest = -1;

    for (size_t i = 0; i < maze->size; i++)
        if ((nodes[i] < lowest || lowest == (size_t) -1) &&
        maze->buffer[i] != 'X' && maze->buffer[i] != '\n' &&
        !is_surrounded(nodes, maze, i)) {
            lowest_index = i;
            lowest = nodes[i];
        }
    return (lowest_index);
}

static void solve_maze(size_t *nodes, maze_t *maze)
{
    while (nodes[maze->size - 1] == (size_t) -1)
        set_around(nodes, maze, get_lowest_node(nodes, maze));
}

int solver(char const **argv)
{
    maze_t *maze = NULL;
    size_t *nodes = NULL;

    maze = load_maze(argv[1]);
    if (!maze)
        return (84);
    nodes = init_nodes(maze);
    if (!nodes)
        return (84);
    solve_maze(nodes, maze);
    backtrace(nodes, maze);
    write(1, maze->buffer, maze->size);
    return (0);
}