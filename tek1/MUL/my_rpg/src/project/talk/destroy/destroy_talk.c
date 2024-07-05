/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** destroy_talk
*/

#include <stdlib.h>
#include <stdio.h>
#include "talk/structs.h"
#include "talk/internal.h"

void destroy_talk(talk_t *talk)
{
    if (!talk)
        return;
    (talk->left_name) ? sfText_destroy(talk->left_name) : NULL;
    (talk->right_name) ? sfText_destroy(talk->right_name) : NULL;
    (talk->left_sprite) ? sfTexture_destroy(talk->left_sprite) : NULL;
    (talk->right_sprite) ? sfTexture_destroy(talk->right_sprite) : NULL;
    (talk->font) ? sfFont_destroy(talk->font) : NULL;
    for (int i = 0; i < SIZE_BUF_NODES; i++)
        (talk->node[i]) ? destroy_talk_node(talk->node[i]) : NULL;
    (talk->node) ? free(talk->node) : NULL;
    free(talk);
}