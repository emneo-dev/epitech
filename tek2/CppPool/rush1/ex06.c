/*
** EPITECH PROJECT, 2021
** ex06.c
** File description:
** ex06
*/

#include <stdio.h>

#include "new.h"
#include "list.h"
#include "int.h"
#include "iterator.h"

void print_object(Object *obj)
{
    char *str = NULL;

    if (!obj)
        return;
    str = str(obj);
    printf("%s", str);
    free(str);
}

void println_object(Object *obj)
{
    print_object(obj);
    printf("\n");
}

void test_push_front(ListClass *list)
{
    printf("Add objects in front (push_front) :\n");
    list->__push_front__(list, Int, 3);
    printf("Add <Int (3)>\n");
    list->__push_front__(list, Int, 2);
    printf("Add <Int (2)>\n");
    list->__push_front__(list, Int, 1);
    printf("Add <Int (1)>\n");
    printf("Size : %ld\n", list->_size);
    println_object(list);
}

void test_push_back(ListClass *list)
{
    printf("Add objects in back (push_back) :\n");
    list->__push_back__(list, Int, 4);
    printf("Add <Int (4)>\n");
    list->__push_back__(list, Int, 5);
    printf("Add <Int (5)>\n");
    list->__push_back__(list, Int, 6);
    printf("Add <Int (6)>\n");
    printf("Size : %ld\n", list->_size);
    println_object(list);
}

void test_pop_back(ListClass *list)
{
    printf("Remove objects from back (pop_back) :\n");
    list->__pop_back__(list);
    list->__pop_back__(list);
    list->__pop_back__(list);
    printf("Size : %ld\n", list->_size);
    println_object(list);
}

void test_pop_front(ListClass *list)
{
    printf("Remove objects from front (pop_front) :\n");
    list->__pop_front__(list);
    list->__pop_front__(list);
    list->__pop_front__(list);
    printf("Size : %ld\n", list->_size);
    println_object(list);
}

void test_iteration_get(ListClass *list)
{
    Iterator *it = begin(list);
    Iterator *it_end = end(list);

    printf("Try itering with for (iterator get) :\n");
    for (; lt(it, it_end); incr(it)) {
        println_object(getval(it));
    }
    delete(it_end);
    delete(it);
}

void test_iteration_set(ListClass *list)
{
    int i = list->_size;
    Iterator *it = begin(list);
    Iterator *it_end = end(list);

    printf("Try reversing nodes (iterator set) :\n");
    for (; lt(it, it_end); incr(it), i--) {
        setval(it, Int, i);
        println_object(getval(it));
    }
    delete(it_end);
    delete(it);
}

int main(void)
{
    ListClass *list = (ListClass *)new(List);

    printf("Void List :\n");
    println_object(list);
    printf("\n");

    test_push_front(list);
    printf("\n");
    test_push_back(list);
    printf("\n");
    test_iteration_get(list);
    printf("\n");
    test_iteration_set(list);
    printf("\n");
    test_pop_front(list);
    printf("\n");
    test_pop_back(list);
    printf("\n");

    delete(list);
    return (0);
}