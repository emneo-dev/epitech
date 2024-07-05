/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** Execute a given function on each node of a linked list
*/

#include <mylist.h>
#include <my.h>
#include <my_apply_on_nodes.h>

int my_apply_on_nodes(linked_list_t *begin, int (*f)(void *))
{
    for (begin; begin != 0; begin = begin->next)
        (*f)(begin->data);
    return (0);
}
