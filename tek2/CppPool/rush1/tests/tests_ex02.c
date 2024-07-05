/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPrush1-mathias.ressort
** File description:
** tests_ex02
*/

#include <criterion/criterion.h>
#include <signal.h>

#include "new.h"
#include "point.h"
#include "vertex.h"

TestSuite(ex02, .timeout=1);

Test(ex02, base_point_example)
{
    Object *point = new(Point, 42, -42);
    char *point_str = NULL;

    cr_assert_not_null(point);
    point_str = str(point);
    cr_expect_str_eq(point_str, "<Point (42, -42)>");
    free(point_str);
    delete(point);
}

Test(ex02, base_vertex_example)
{
    Object *vertex = new(Vertex, 0, 1, 2);
    char *vertex_str = NULL;

    cr_assert_not_null(vertex);
    vertex_str = str(vertex);
    cr_expect_str_eq(vertex_str, "<Vertex (0, 1, 2)>");
    free(vertex_str);
    delete(vertex);
}

Test(ex02, vertex_too_much_new_arg)
{
    Object *vertex = new(Vertex, 0, 1, 2, 3, 4, 5);
    char *vertex_str = NULL;

    cr_assert_not_null(vertex);
    vertex_str = str(vertex);
    cr_expect_str_eq(vertex_str, "<Vertex (0, 1, 2)>");
    free(vertex_str);
    delete(vertex);
}

Test(ex02, point_too_much_new_arg)
{
    Object *point = new(Point, 42, -42, 0, 1, 2);
    char *point_str = NULL;

    cr_assert_not_null(point);
    point_str = str(point);
    cr_expect_str_eq(point_str, "<Point (42, -42)>");
    free(point_str);
    delete(point);
}