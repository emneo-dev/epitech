/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** double_list_dump
*/

#include <stdio.h>

#include "double_list.h"

void double_list_dump(double_list_t list)
{
    if (!list)
        return;
    for (; list; list = list->next)
        printf("%f\n", list->value);
}