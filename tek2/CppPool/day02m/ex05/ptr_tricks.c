/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02M-alexandre.flion
** File description:
** ptr_tricks
*/

#include <stdio.h>

#include "ptr_tricks.h"

whatever_t *get_struct_ptr(const int *member_ptr)
{
    return (whatever_t *)
        ((char *)member_ptr - (size_t) &((whatever_t *)0)->member);
}

int get_array_nb_elem(const int *ptr1, const int *ptr2)
{
    int offset = ptr1 - ptr2;

    return (offset < 0) ? -offset : offset;
}
