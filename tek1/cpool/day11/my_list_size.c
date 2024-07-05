/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** Put all the parameters into a linked list
*/

#include <mylist.h>
#include <my.h>
#include <my_list_size.h>

int my_list_size(linked_list_t const *begin)
{
    int i = 0;


    if (begin == 0)
        return (0);
    for (i = 1; begin->next != 0; ++i)
        begin = begin->next;
    return (i);
}
