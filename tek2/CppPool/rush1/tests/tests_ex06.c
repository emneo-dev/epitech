/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPrush1-mathias.ressort [SSH: 192.168.0.19]
** File description:
** tests_ex04
*/

#include <criterion/criterion.h>
#include <signal.h>

#include "new.h"
#include "int.h"
#include "float.h"
#include "char.h"
#include "int.h"
#include "list.h"

TestSuite(ex06, .timeout=1);

Test(ex06, list_void)
{
    Object *list = new(List);
    char *obj_str = NULL;

    cr_assert_not_null(list);
    obj_str = str(list);
    cr_assert_str_eq(obj_str, "<List ()>");
    free(obj_str);
    delete(list);
}

Test(ex06, list_pushfront)
{
    ListClass *list = (ListClass *)new(List);
    char *obj_str = NULL;

    cr_assert_not_null(list);

    list->__push_front__(list, Int, 5);
    obj_str = str(list);
    cr_assert_str_eq(obj_str, "<List (<Int (5)>)>");
    free(obj_str);


    list->__push_front__(list, Int, 4);
    list->__push_front__(list, Int, 3);
    list->__push_front__(list, Int, 2);
    list->__push_front__(list, Int, 1);
    obj_str = str(list);
    cr_assert_str_eq(obj_str, "<List (<Int (1)>, <Int (2)>, <Int (3)>, <Int (4)>, <Int (5)>)>");
    free(obj_str);

    obj_str = str(list->_first);
    cr_assert_str_eq(obj_str, "<Int (1)>");
    free(obj_str);
    obj_str = str(list->_last);
    cr_assert_str_eq(obj_str, "<Int (5)>");
    free(obj_str);
    delete(list);
}

Test(ex06, list_pushback)
{
    ListClass *list = (ListClass *)new(List);
    char *obj_str = NULL;

    cr_assert_not_null(list);
    list->__push_back__(list, Int, 1);

     obj_str = str(list);
    cr_assert_str_eq(obj_str, "<List (<Int (1)>)>");
    free(obj_str);
    list->__push_back__(list, Int, 2);
    list->__push_back__(list, Int, 3);
    list->__push_back__(list, Int, 4);
    list->__push_back__(list, Int, 5);
    obj_str = str(list);
    cr_assert_str_eq(obj_str, "<List (<Int (1)>, <Int (2)>, <Int (3)>, <Int (4)>, <Int (5)>)>");
    free(obj_str);

    obj_str = str(list->_first);
    cr_assert_str_eq(obj_str, "<Int (1)>");
    free(obj_str);
    obj_str = str(list->_last);
    cr_assert_str_eq(obj_str, "<Int (5)>");
    free(obj_str);

    delete(list);
}

Test(ex06, list_pushfront_popfront)
{
    ListClass *list = (ListClass *)new(List);
    char *obj_str = NULL;

    cr_assert_not_null(list);
    list->__push_front__(list, Int, 5);
    list->__push_front__(list, Int, 4);
    list->__push_front__(list, Int, 3);
    list->__push_front__(list, Int, 2);
    list->__push_front__(list, Int, 1);
    obj_str = str(list);
    cr_assert_str_eq(obj_str, "<List (<Int (1)>, <Int (2)>, <Int (3)>, <Int (4)>, <Int (5)>)>");
    free(obj_str);
    list->__pop_front__(list);
    obj_str = str(list);
    cr_assert_str_eq(obj_str, "<List (<Int (2)>, <Int (3)>, <Int (4)>, <Int (5)>)>");
    free(obj_str);
    list->__pop_front__(list);
    obj_str = str(list);
    cr_assert_str_eq(obj_str, "<List (<Int (3)>, <Int (4)>, <Int (5)>)>");
    free(obj_str);
    list->__pop_front__(list);
    obj_str = str(list);
    cr_assert_str_eq(obj_str, "<List (<Int (4)>, <Int (5)>)>");
    free(obj_str);
    list->__pop_front__(list);
    obj_str = str(list);
    cr_assert_str_eq(obj_str, "<List (<Int (5)>)>");
    free(obj_str);
    list->__pop_front__(list);
    obj_str = str(list);
    cr_assert_str_eq(obj_str, "<List ()>");
    free(obj_str);

    cr_assert_null(list->_first);
    cr_assert_null(list->_last);

    delete(list);
}

Test(ex06, list_pushfront_popback)
{
    ListClass *list = (ListClass *)new(List);
    char *obj_str = NULL;

    cr_assert_not_null(list);
    list->__push_front__(list, Int, 5);
    list->__push_front__(list, Int, 4);
    list->__push_front__(list, Int, 3);
    list->__push_front__(list, Int, 2);
    list->__push_front__(list, Int, 1);
    obj_str = str(list);
    cr_assert_str_eq(obj_str, "<List (<Int (1)>, <Int (2)>, <Int (3)>, <Int (4)>, <Int (5)>)>");
    free(obj_str);
    list->__pop_back__(list);
    obj_str = str(list);
    cr_assert_str_eq(obj_str, "<List (<Int (1)>, <Int (2)>, <Int (3)>, <Int (4)>)>");
    list->__pop_back__(list);
    obj_str = str(list);
    cr_assert_str_eq(obj_str, "<List (<Int (1)>, <Int (2)>, <Int (3)>)>");
    list->__pop_back__(list);
    obj_str = str(list);
    cr_assert_str_eq(obj_str, "<List (<Int (1)>, <Int (2)>)>");
    list->__pop_back__(list);
    obj_str = str(list);
    cr_assert_str_eq(obj_str, "<List (<Int (1)>)>");
    list->__pop_back__(list);
    obj_str = str(list);
    cr_assert_str_eq(obj_str, "<List ()>");
    free(obj_str);

    cr_assert_null(list->_first);
    cr_assert_null(list->_last);

    delete(list);
}

Test(ex06, list_pushback_popfront)
{
    ListClass *list = (ListClass *)new(List);
    char *obj_str = NULL;

    cr_assert_not_null(list);
    list->__push_back__(list, Int, 1);
    list->__push_back__(list, Int, 2);
    list->__push_back__(list, Int, 3);
    list->__push_back__(list, Int, 4);
    list->__push_back__(list, Int, 5);
    obj_str = str(list);
    cr_assert_str_eq(obj_str, "<List (<Int (1)>, <Int (2)>, <Int (3)>, <Int (4)>, <Int (5)>)>");
    free(obj_str);
    list->__pop_front__(list);
    obj_str = str(list);
    cr_assert_str_eq(obj_str, "<List (<Int (2)>, <Int (3)>, <Int (4)>, <Int (5)>)>");
    free(obj_str);
    list->__pop_front__(list);
    obj_str = str(list);
    cr_assert_str_eq(obj_str, "<List (<Int (3)>, <Int (4)>, <Int (5)>)>");
    free(obj_str);
    list->__pop_front__(list);
    obj_str = str(list);
    cr_assert_str_eq(obj_str, "<List (<Int (4)>, <Int (5)>)>");
    free(obj_str);
    list->__pop_front__(list);
    obj_str = str(list);
    cr_assert_str_eq(obj_str, "<List (<Int (5)>)>");
    free(obj_str);
    list->__pop_front__(list);
    obj_str = str(list);
    cr_assert_str_eq(obj_str, "<List ()>");
    free(obj_str);

    cr_assert_null(list->_first);
    cr_assert_null(list->_last);

    delete(list);
}

Test(ex06, list_pushback_popback)
{
    ListClass *list = (ListClass *)new(List);
    char *obj_str = NULL;

    cr_assert_not_null(list);

    // add back nodes
    list->__push_back__(list, Int, 1);
    list->__push_back__(list, Int, 2);
    list->__push_back__(list, Int, 3);
    list->__push_back__(list, Int, 4);
    list->__push_back__(list, Int, 5);
    obj_str = str(list);
    cr_assert_str_eq(obj_str, "<List (<Int (1)>, <Int (2)>, <Int (3)>, <Int (4)>, <Int (5)>)>");
    free(obj_str);

    // remove back nodes
    list->__pop_back__(list);
    obj_str = str(list);
    cr_assert_str_eq(obj_str, "<List (<Int (1)>, <Int (2)>, <Int (3)>, <Int (4)>)>");
    list->__pop_back__(list);
    obj_str = str(list);
    cr_assert_str_eq(obj_str, "<List (<Int (1)>, <Int (2)>, <Int (3)>)>");
    list->__pop_back__(list);
    obj_str = str(list);
    cr_assert_str_eq(obj_str, "<List (<Int (1)>, <Int (2)>)>");
    list->__pop_back__(list);
    obj_str = str(list);
    cr_assert_str_eq(obj_str, "<List (<Int (1)>)>");
    list->__pop_back__(list);
    obj_str = str(list);
    cr_assert_str_eq(obj_str, "<List ()>");
    free(obj_str);

    cr_assert_null(list->_first);
    cr_assert_null(list->_last);

    delete(list);
}

Test(ex06, list_get_at)
{
    ListClass *list = (ListClass *)new(List);
    Object *obj = NULL;
    char *obj_str = NULL;
    cr_assert_not_null(list);

    // add back nodes
    list->__push_back__(list, Int, 1);
    list->__push_back__(list, Int, 2);
    list->__push_back__(list, Int, 3);
    list->__push_back__(list, Int, 4);
    list->__push_back__(list, Int, 5);
    obj_str = str(list);
    cr_assert_str_eq(obj_str, "<List (<Int (1)>, <Int (2)>, <Int (3)>, <Int (4)>, <Int (5)>)>");
    free(obj_str);

    // check int
    obj = list->__get_at__(list, 0);
    obj_str = str(obj);
    cr_assert_str_eq(obj_str, "<Int (1)>");
    free(obj_str);
    obj = list->__get_at__(list, 1);
    obj_str = str(obj);
    cr_assert_str_eq(obj_str, "<Int (2)>");
    free(obj_str);
    obj = list->__get_at__(list, 2);
    obj_str = str(obj);
    cr_assert_str_eq(obj_str, "<Int (3)>");
    free(obj_str);
    obj = list->__get_at__(list, 3);
    obj_str = str(obj);
    cr_assert_str_eq(obj_str, "<Int (4)>");
    free(obj_str);
    obj = list->__get_at__(list, 4);
    obj_str = str(obj);
    cr_assert_str_eq(obj_str, "<Int (5)>");
    free(obj_str);

    delete(list);
}

Test(ex06, list_iter_get)
{
    ListClass *list = (ListClass *)new(List);
    Object *obj = NULL;
    char *obj_str = NULL;
    cr_assert_not_null(list);

    // add back nodes
    list->__push_back__(list, Int, 1);
    list->__push_back__(list, Int, 2);
    list->__push_back__(list, Int, 3);
    list->__push_back__(list, Int, 4);
    list->__push_back__(list, Int, 5);
    obj_str = str(list);
    cr_assert_str_eq(obj_str, "<List (<Int (1)>, <Int (2)>, <Int (3)>, <Int (4)>, <Int (5)>)>");
    free(obj_str);

    int iter = 0;
    char *str2 = NULL;
    for (Iterator *it = begin(list); lt(it, end(list)); incr(it), iter++) {
        obj = list->__get_at__(list, iter);
        str2 = str(obj);
        obj_str = str(it->__getval__(it));

        cr_assert_str_eq(obj_str, str2);
        free(obj_str);
        free(str2);
    }

    delete(list);
}

Test(ex06, list_iter_set)
{
    ListClass *list = (ListClass *)new(List);
    char *obj_str = NULL;
    cr_assert_not_null(list);

    // add back nodes
    list->__push_back__(list, Int, 1);
    list->__push_back__(list, Int, 2);
    list->__push_back__(list, Int, 3);
    list->__push_back__(list, Int, 4);
    list->__push_back__(list, Int, 5);
    obj_str = str(list);
    cr_assert_str_eq(obj_str, "<List (<Int (1)>, <Int (2)>, <Int (3)>, <Int (4)>, <Int (5)>)>");
    free(obj_str);

    for (Iterator *it = begin(list); lt(it, end(list)); incr(it)) {
        it->__setval__(it, Int, 0);
    }
    obj_str = str(list);
    cr_assert_str_eq(obj_str, "<List (<Int (0)>, <Int (0)>, <Int (0)>, <Int (0)>, <Int (0)>)>");
    free(obj_str);

    delete(list);
}