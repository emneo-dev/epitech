/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** double_list_dump
*/

#include <stdio.h>

#include "generic_list.h"

void list_dump(list_t list, value_displayer_t val_disp)
{
    if (!list)
        return;
    for (; list; list = list->next)
        val_disp(list->value);
}