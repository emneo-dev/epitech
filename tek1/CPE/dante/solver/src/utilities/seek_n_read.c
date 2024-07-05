/*
** EPITECH PROJECT, 2020
** CPE_dante
** File description:
** Read a file and returns a buffer upon completion
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "struct.h"

maze_t *seek_n_read(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    off_t offset = 0;
    maze_t *maze = NULL;

    if (fd == -1)
        return (NULL);
    maze = malloc(sizeof(maze_t));
    if (!maze)
        return (NULL);
    offset = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);
    maze->buffer = malloc(sizeof(char) * offset + 1);
    if (!maze->buffer)
        return (NULL);
    maze->size = read(fd, maze->buffer, offset);
    maze->buffer[maze->size] = '\0';
    maze->width = 0;
    close(fd);
    return (maze);
}