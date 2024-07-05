/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** Reverse the nodes of a linked list
*/

#include <mylist.h>
#include <my.h>
#include <my_rev_list.h>

void my_rev_list(linked_list_t **begin)
{
    struct linked_list *list;
    struct linked_list *next;
    struct linked_list *prev;

    list = *begin;
    prev = 0;
    while (list != 0) {
        next = list->next;
        list->next = prev;
        prev = list;
        list = next;
    }
    *begin = prev;
}
