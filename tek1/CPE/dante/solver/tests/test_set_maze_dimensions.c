/*
** EPITECH PROJECT, 2020
** CPE_dante
** File description:
** Test for the set_maze_dimensions function
*/

#include <string.h>
#include <criterion/criterion.h>
#include "prototype.h"

TestSuite(set_maze_dimensions, .timeout = 1);

Test(set_maze_dimensions, normal_file)
{
    maze_t *maze = NULL;

    maze = malloc(sizeof(maze_t));
    cr_assert(maze);
    maze->buffer = malloc(sizeof(char) * 100);
    cr_assert(maze->buffer);
    strcpy(maze->buffer, "I like pastas\nAnd lasagnas");
    maze->size = 26;
    set_maze_dimensions(maze);
    cr_expect_eq(maze->width, 13);
}

Test(set_maze_dimensions, normal_maze)
{
    maze_t *maze = NULL;

    maze = seek_n_read("tests/tests_files/simple_maze.txt");
    cr_assert_neq(maze, NULL);
    set_maze_dimensions(maze);
    cr_expect_eq(maze->width, 24);
    cr_expect_eq(maze->height, 6);
}