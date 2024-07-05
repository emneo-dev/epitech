/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** queue_is_empty
*/

#include "queue.h"

bool queue_is_empty(queue_t queue)
{
    return list_is_empty(queue);
}