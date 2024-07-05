/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** structs
*/

#ifndef TALK_STRUCTS_H_
#define TALK_STRUCTS_H_

#include "SFML/Graphics.h"

typedef struct person_s {
    char *sprite_path;
    char *name;
} person_t;

typedef struct new_talk_node_s {
    unsigned char index;
    unsigned char nb_options;
    unsigned char who_is_talking;
    char *text;
    char *first_option;
    char *second_option;
    unsigned char first_option_index;
    unsigned char second_option_index;
    unsigned char is_end;
} new_talk_node_t;

// who_is_talking is on 0 when the person talking is unknown
// 1 when it is the left, and 2 when right
typedef struct talk_node_s {
    unsigned char nb_options;
    sfText *text;
    sfText *first_option;
    sfText *second_option;
    unsigned char who_is_talking;
    unsigned char first_option_index;
    unsigned char second_option_index;
    unsigned char is_end;
} talk_node_t;

typedef struct talk_s {
    sfTexture *left_sprite;
    sfTexture *right_sprite;
    talk_node_t **node;
    sfText *left_name;
    sfText *right_name;
    sfFont *font;
} talk_t;

#endif /* !TALK_STRUCTS_H_ */
