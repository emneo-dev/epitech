/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019 [WSL: Ubuntu]
** File description:
** push_a_to_b
*/

#include <unistd.h>
#include "pushswap.h"

void push_a_to_b(t_link_t **a, t_link_t **b)
{
    if (a == NULL || b == NULL)
        return;
    if (*a == NULL)
        return;
    t_link_t *tmp = (*a)->next;
    (*a)->next = (*b);
    *b = *a;
    *a = tmp;
}