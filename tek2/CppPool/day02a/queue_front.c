/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** queue_front
*/

#include "queue.h"

void *queue_front(queue_t queue)
{
    return list_get_elem_at_front(queue);
}