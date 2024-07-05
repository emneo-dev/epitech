/*
**
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** Execute a given function on the matching node of a linked list
*/

#include <mylist.h>
#include <my.h>
#include <my_find_node.h>

linked_list_t *my_find_node(linked_list_t const *begin, void const *data_ref,
                            int (*cmp)())
{
    for (begin; begin != 0; begin = begin->next)
        if (!(cmp(begin->data, data_ref)))
            return (begin);
    return (0);
}
