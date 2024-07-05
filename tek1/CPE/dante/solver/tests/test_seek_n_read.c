/*
** EPITECH PROJECT, 2020
** CPE_dante
** File description:
** Test for the seek_n_read function
*/

#include <criterion/criterion.h>
#include "prototype.h"

TestSuite(seek_n_read, .timeout = 1);

Test(seek_n_read, non_existent_file)
{
    maze_t *maze = NULL;

    maze = seek_n_read("issou.maze");
    cr_assert_eq(maze, NULL);
}

Test(seek_n_read, normal_file)
{
    maze_t *maze = NULL;

    maze = seek_n_read("tests/tests_files/normal_file.txt");
    cr_assert_neq(maze, NULL);
    cr_assert_neq(maze->buffer, NULL);
    cr_expect_eq(maze->size, 26);
    cr_expect_eq(maze->width, 0);
    cr_expect_str_eq(maze->buffer, "I like pastas\nAnd lasagnas");
}