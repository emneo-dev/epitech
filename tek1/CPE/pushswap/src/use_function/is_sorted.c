/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019 [WSL: Ubuntu]
** File description:
** is_sorted
*/

#include <stdlib.h>
#include "pushswap.h"

int is_sorted(t_link_t *list)
{
    if (list == NULL)
        return (1);
    for (; list->next != NULL; list = list->next)
        if (list->value > list->next->value)
            return (0);
    return (1);
}