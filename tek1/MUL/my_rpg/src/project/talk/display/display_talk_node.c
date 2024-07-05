/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** display_talk_node
*/

#include "utility.h"
#include "talk/internal.h"

void display_talk_node(talk_t *talk, cb_talk_node_t *cb, sfRenderWindow *window)
{
    if (!talk->node[cb->is_end]) {
        my_puterr("Could not display talk node! (Index not set)\n");
        cb->is_end = 1;
        return;
    }
    switch (talk->node[cb->index]->nb_options)
    {
    case 0:
        return (display_no_options(talk, cb, window));
    case 1:
        return (display_one_option(talk, cb, window));
    case 2:
        return (display_two_options(talk, cb, window));
    default:
        my_puterr("Could not display talk node! (Unknown options)\n");
        cb->is_end = 1;
        break;
    }
}