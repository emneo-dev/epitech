/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** destroy_node
*/

#include <stdlib.h>
#include "talk/structs.h"

void destroy_talk_node(talk_node_t *node)
{
    (node->first_option) ? sfText_destroy(node->first_option) : (void) NULL;
    (node->second_option) ? sfText_destroy(node->second_option) : (void) NULL;
    (node->text) ? sfText_destroy(node->text) : (void) NULL;
    free(node);
}