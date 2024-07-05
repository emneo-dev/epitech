/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** queue_push
*/

#include "queue.h"

bool queue_push(queue_t *queue_ptr, void *elem)
{
    return list_add_elem_at_back(queue_ptr, elem);
}