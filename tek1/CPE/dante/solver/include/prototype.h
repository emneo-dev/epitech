/*
** EPITECH PROJECT, 2020
** CPE_dante
** File description:
** Header file for all prototypes
*/

#ifndef SAMPLE_H_
#define SAMPLE_H_

#include "struct.h"

int solver(char const **argv);

// Some category

void backtrace(size_t *nodes, maze_t *maze);
int can_go(size_t *nodes, maze_t *maze, size_t index);
void set_around(size_t *nodes, maze_t *maze, size_t index);
int is_surrounded(size_t *nodes, maze_t *maze, size_t index);
size_t *init_nodes(maze_t const *maze);

// Utilities

maze_t *seek_n_read(char const *filepath);
void set_maze_dimensions(maze_t *maze);

#endif /* !SAMPLE_H_ */
