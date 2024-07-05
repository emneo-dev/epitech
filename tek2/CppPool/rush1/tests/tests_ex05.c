/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPrush1-mathias.ressort
** File description:
** tests_ex05
*/

#include <criterion/criterion.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array.h"
#include "new.h"
#include "int.h"
#include "float.h"

TestSuite(ex05, .timeout=1);

Test(ex05, array_set_item)
{
    Object *array = new (Array, 10, Int, 0);
    char *obj_str = NULL;

    cr_assert_not_null(array);
    setitem(array, 5, 12);
    obj_str = str(array);
    cr_assert_str_eq(obj_str, "<Array (<Int (0)>, <Int (0)>, <Int (0)>, <Int (0)>, <Int (0)>, <Int (12)>, <Int (0)>, <Int (0)>, <Int (0)>, <Int (0)>)>");
    free(obj_str);
    size_t iter = 0;
    for (Iterator *it = begin(array); lt(it, end(array)); incr(it), iter++)
        setitem(array, iter, iter);
    obj_str = str(array);
    cr_assert_str_eq(obj_str, "<Array (<Int (0)>, <Int (1)>, <Int (2)>, <Int (3)>, <Int (4)>, <Int (5)>, <Int (6)>, <Int (7)>, <Int (8)>, <Int (9)>)>");
    free(obj_str);

    delete(array);
}

Test(ex05, array_get_item)
{
    Object *array = new (Array, 10, Int, 0);
    Object *obj = NULL;
    char *obj_str = NULL;

    cr_assert_not_null(array);
    setitem(array, 5, 12);
    obj_str = str(array);
    cr_assert_str_eq(obj_str, "<Array (<Int (0)>, <Int (0)>, <Int (0)>, <Int (0)>, <Int (0)>, <Int (12)>, <Int (0)>, <Int (0)>, <Int (0)>, <Int (0)>)>");
    free(obj_str);
    size_t iter = 0;
    char *s2 = NULL;
    for (Iterator *it = begin(array); lt(it, end(array)); incr(it), iter++) {
        obj = getitem(array, iter);
        s2 = str(obj);
        obj_str = str(it->__getval__(it));
        cr_assert_str_eq(obj_str, s2);
        free(obj_str);
        free(s2);
    }
    delete(array);
}

Test(ex05, array_len)
{
    Object *array = new (Array, 10, Int, 0);

    cr_assert_not_null(array);
    cr_assert_eq(len(array), 10);
    delete(array);
}

Test(ex05, array_begin_null)
{
    Object *array = new (Array, 10, Int, 0);
    Object *it = begin(array);

    cr_assert_not_null(it);
    delete(it);
    delete(array);
}

Test(ex05, array_end_null)
{
    Object *array = new( Array, 10, Int, 0);
    Object *it = begin(array);
    Object *it_end = end(array);

    cr_assert_not_null(it_end);
    delete (it);
    delete (it_end);
    delete (array);
}

Test(ex05, array_incr_simple)
{
    Object *array = new (Array, 10, Int, 0);
    Object *it = begin(array);
    Object *it_end = end(array);
    char *buf = NULL;

    cr_assert_not_null(array);
    cr_assert_not_null(it);
    cr_assert_not_null(it_end);
    setitem(array, 0, 12);
    buf = str(getval(it));
    cr_expect_str_eq("<Int (12)>", buf);
    delete(it);
    delete(it_end);
    delete(array);
}

Test(ex05, array_incr)
{
    Object *array = new (Array, 10, Int, 0);
    Object *it = begin(array);
    Object *it_end = end(array);
    int value = 1;
    char *buf = NULL;

    cr_assert_not_null(array);
    cr_assert_not_null(it);
    cr_assert_not_null(it_end);
    setitem(array, 5, 12);
    for (char *nbr; lt(it, it_end); value++)
    {
        if (value == 6)
            nbr = "<Int (12)>";
        else
            nbr = "<Int (0)>";
        buf = str(getval(it));
        cr_expect_str_eq(nbr, buf);
        incr(it);
    }
    delete(it);
    delete(it_end);
    delete(array);
}

Test(ex05, array_decr_abrt, .signal=SIGABRT)
{
    Object *array = new (Array, 10, Int, 0);
    Object *it = begin(array);
    Object *it_end = end(array);

    cr_assert_not_null(array);
    cr_assert_not_null(it);
    cr_assert_not_null(it_end);
    setitem(array, -42, -42);
    delete(it);
    delete(it_end);
    delete(array);
}

Test(ex05, array_decr)
{
    Object *array = new (Array, 10, Int, 0);
    Object *it = begin(array);
    Object *it_end = end(array);

    cr_assert_not_null(array);
    cr_assert_not_null(it);
    cr_assert_not_null(it_end);
    setitem(array, 6, 4);
    getitem(array, -42, -42);
    delete(array);
    delete(it_end);
    delete(it);
}

Test(ex05, array_delete_sig, .signal=SIGABRT)
{
    Object *array = NULL;
    Object *it = NULL;
    Object *it_end = NULL;

    delete(array);
    delete(it_end);
    delete(it);
}

Test(ex05, array_new_sig, .signal=SIGABRT)
{
    Object *array = new(Array, -1, Int, 0);
    Object *it = begin(array);
    Object *it_end = end(array);

    cr_assert_not_null(array);
    cr_assert_not_null(it);
    cr_assert_not_null(it_end);
    setitem(array, 6, 4);
    delete(array);
    delete(it_end);
    delete(it);
}

Test(ex05, array_new_float, .signal=SIGABRT)
{
    Object *array = new(Array);
    Object *it = begin(array);
    Object *it_end = end(array);

    cr_assert_not_null(array);
    cr_assert_not_null(it);
    cr_assert_not_null(it_end);
    setitem(array, 6, 4);
    delete(array);
    delete(it_end);
    delete(it);
}

Test(ex05, array_incr_sig)
{
    Object *array = new(Array, 10, Int, 0);
    Object *it = begin(array);
    Object *it_begin = begin(array);
    Object *it_end = end(array);
    int value = 1;
    char *buf = NULL;

    cr_assert_not_null(array);
    cr_assert_not_null(it);
    cr_assert_not_null(it_end);
    setitem(array, 5, 12);
    for (char *nbr; lt(it, it_begin); value++)
    {
        if (value == 6)
            nbr = "<Int (12)>";
        else
            nbr = "<Int (0)>";
        buf = str(getval(it));
        cr_expect_str_eq(nbr, buf);
        incr(it);
    }
    delete(it);
    delete(it_end);
    delete(array);
}

Test(ex05, array_new_array, .signal=SIGABRT)
{
    Object *array = new (Array, 10, Array, 5);
    Object *it = begin(array);
    Object *it_end = end(array);

    cr_assert_not_null(array);
    cr_assert_not_null(it);
    cr_assert_not_null(it_end);
    setitem(array, 6, 4);
    delete(array);
    delete(it_end);
    delete(it);
}