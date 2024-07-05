/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** Put all the parameters into a linked list
*/

#include <mylist.h>
#include <my.h>
#include <my_params_to_list.h>
#include <stdlib.h>

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    struct linked_list *list;

    list = 0;
    for (int i = 0; i < ac; ++i)
        my_put_in_list(&list, av[i]);
    return (list);
}

static int my_put_in_list(struct linked_list **list, void *data)
{
    struct linked_list *element;

    element = malloc(sizeof(*element));
    element->data = data;
    element->next = *list;
    *list = element;
    return (0);
}
