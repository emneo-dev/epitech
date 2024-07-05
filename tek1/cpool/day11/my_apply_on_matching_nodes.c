/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** Execute a given function on the matching node of a linked list
*/

#include <mylist.h>
#include <my.h>
#include <my_apply_on_matching_nodes.h>

int my_apply_on_matching_nodes(linked_list_t *begin, int (*f)(),
                               void const *data_ref, int (*cmp)())
{
    for (begin; begin != 0; begin = begin->next)
        if (!(cmp(begin->data, data_ref)))
            (*f)(begin->data);
    return (0);
}
