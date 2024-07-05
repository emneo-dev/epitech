/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPrush1-mathias.ressort
** File description:
** tests_ex03
*/

#include <criterion/criterion.h>
#include <signal.h>

#include "new.h"
#include "point.h"
#include "vertex.h"

TestSuite(ex03, .timeout=1);

Test(ex03, base_vertex_addition)
{
    Object *vertex_1 = new(Vertex, 1, 2, 3);
    Object *vertex_2 = new(Vertex, 4, 5, 6);
    Object *vertex_result = NULL;
    char *vertex_str = NULL;

    cr_assert_not_null(vertex_1);
    cr_assert_not_null(vertex_2);
    vertex_result = addition(vertex_1, vertex_2);
    cr_assert_not_null(vertex_result);
    vertex_str = str(vertex_result);
    cr_assert_str_eq(vertex_str, "<Vertex (5, 7, 9)>");
    free(vertex_str);
    delete(vertex_1);
    delete(vertex_2);
    delete(vertex_result);
}

Test(ex03, base_vertex_subtraction)
{
    Object *vertex_1 = new(Vertex, 1, 2, 3);
    Object *vertex_2 = new(Vertex, 4, 5, 6);
    Object *vertex_result = NULL;
    char *vertex_str = NULL;

    cr_assert_not_null(vertex_1);
    cr_assert_not_null(vertex_2);
    vertex_result = subtraction(vertex_1, vertex_2);
    cr_assert_not_null(vertex_result);
    vertex_str = str(vertex_result);
    cr_assert_str_eq(vertex_str, "<Vertex (-3, -3, -3)>");
    free(vertex_str);
    delete(vertex_1);
    delete(vertex_2);
    delete(vertex_result);
}

Test(ex03, base_point_addition)
{
    Object *point_1 = new(Point, 12, 13);
    Object *point_2 = new(Point, 2, 2);
    Object *point_result = NULL;
    char *point_str = NULL;

    cr_assert_not_null(point_1);
    cr_assert_not_null(point_2);
    point_result = addition(point_1, point_2);
    cr_assert_not_null(point_result);
    point_str = str(point_result);
    cr_assert_str_eq(point_str, "<Point (14, 15)>");
    free(point_str);
    delete(point_1);
    delete(point_2);
    delete(point_result);
}

Test(ex03, base_point_subtraction)
{
    Object *point_1 = new(Point, 12, 13);
    Object *point_2 = new(Point, 2, 2);
    Object *point_result = NULL;
    char *point_str = NULL;

    cr_assert_not_null(point_1);
    cr_assert_not_null(point_2);
    point_result = subtraction(point_1, point_2);
    cr_assert_not_null(point_result);
    point_str = str(point_result);
    cr_assert_str_eq(point_str, "<Point (10, 11)>");
    free(point_str);
    delete(point_1);
    delete(point_2);
    delete(point_result);
}

Test(ex03, null_point_subtraction, .signal=SIGABRT)
{
    Object *point = new(Point, 12, 13);

    cr_assert_not_null(point);
    subtraction(point, NULL);
}

Test(ex03, null_point_addition, .signal=SIGABRT)
{
    Object *point = new(Point, 12, 13);

    cr_assert_not_null(point);
    addition(point, NULL);
}

Test(ex03, null_vertex_subtraction, .signal=SIGABRT)
{
    Object *vertex = new(Vertex, 12, 13, 42);

    cr_assert_not_null(vertex);
    subtraction(vertex, NULL);
}

Test(ex03, null_vertex_addition, .signal=SIGABRT)
{
    Object *vertex = new(Vertex, 12, 13, 42);

    cr_assert_not_null(vertex);
    addition(vertex, NULL);
}