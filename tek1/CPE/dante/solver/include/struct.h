/*
** EPITECH PROJECT, 2020
** CPE_dante
** File description:
** Header file for all structures
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <stdlib.h>

// Used to store the loaded maze
typedef struct maze_s {
    char *buffer;
    size_t size;
    size_t width;
    size_t height;
} maze_t;

#endif /* !STRUCT_H_ */
