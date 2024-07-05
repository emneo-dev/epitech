/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** launch_talk
*/

#include "talk/internal.h"
#include "talk/structs.h"

int launch_talk(talk_t *talk, sfRenderWindow *window)
{
    cb_talk_node_t cb = {0, 0};

    while (!cb.is_end)
        display_talk_node(talk, &cb, window);
    return (cb.index);
}