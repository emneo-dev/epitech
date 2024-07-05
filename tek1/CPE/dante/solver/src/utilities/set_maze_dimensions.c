/*
** EPITECH PROJECT, 2020
** CPE_dante
** File description:
** Sets the dimensions of the given maze
*/

#include "struct.h"

void set_maze_dimensions(maze_t *maze)
{
    if (!maze || !maze->buffer)
        return;
    for (maze->width = 0; maze->buffer[maze->width] &&
        maze->buffer[maze->width] != '\n'; maze->width++);
    maze->height = (maze->size + 1) / (maze->width + 1);
}