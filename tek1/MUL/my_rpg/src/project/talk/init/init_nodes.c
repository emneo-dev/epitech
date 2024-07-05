/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** init_nodes
*/

#include <stdlib.h>
#include "talk/structs.h"
#include "talk/internal.h"
#include "utility.h"

int init_nodes(talk_t *talk)
{
    talk->node = malloc(sizeof(talk_node_t) * SIZE_BUF_NODES);
    if (talk->node) {
        for (int i = 0; i < SIZE_BUF_NODES; i++)
            talk->node[i] = NULL;
        return (0);
    }
    my_puterr("Could not create talk_node buffer!\n");
    return (1);
}