/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** queue_pop
*/

#include "queue.h"

bool queue_pop(queue_t *queue_ptr)
{
    return list_del_elem_at_front(queue_ptr);
}