/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02A-alexandre.flion
** File description:
** queue_get_size
*/

#include "queue.h"

unsigned int queue_get_size(queue_t queue)
{
    return list_get_size(queue);
}