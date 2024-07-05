/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019 [WSL: Ubuntu]
** File description:
** sa_pa_pb
*/

#include <unistd.h>
#include "pushswap.h"

void ra(t_link_t **list)
{
    if (list == NULL)
        return;
    if (*list == NULL)
        return;
    if ((*list)->next == NULL)
        return;
    t_link_t *current = *list;
    for (; current->next; current = current->next);
    t_link_t *tmp = *list;
    *list = (*list)->next;
    tmp->next = NULL;
    current->next = tmp;
    return;
}

void sa(t_link_t *list)
{
    if (list == NULL)
        return;
    if (list->next == NULL)
        return;
    swap_values(&(list->value), &(list->next->value));
}

void pa(t_link_t **a, t_link_t **b)
{
    push_a_to_b(b, a);
}

void pb(t_link_t **a, t_link_t **b)
{
    push_a_to_b(a, b);
}