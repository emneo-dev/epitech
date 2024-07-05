/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** internal
*/

#ifndef TALK_INTERNAL_H_
#define TALK_INTERNAL_H_

#include "talk/structs.h"

typedef struct cb_talk_node_s {
    unsigned char is_end;
    unsigned char index;
} cb_talk_node_t;

// Currently limited to 256 due to unsigned char capacities
#define SIZE_BUF_NODES 256

// Init
void second_person_init(talk_t *talk, person_t *person);
void first_person_init(talk_t *talk, person_t *person);
int init_font(talk_t *talk, char *font_path);
int init_nodes(talk_t *talk);

// Destroy
void destroy_talk_node(talk_node_t *node);

// Display
void display_no_options(talk_t *talk, cb_talk_node_t *cb,
                        sfRenderWindow *window);
void display_one_option(talk_t *talk, cb_talk_node_t *cb,
                        sfRenderWindow *window);
void display_two_options(talk_t *talk, cb_talk_node_t *cb,
                         sfRenderWindow *window);
int display_talk_text(sfText *text, sfRenderWindow *window);
void display_talk_node(talk_t *talk, cb_talk_node_t *cb,
                       sfRenderWindow *window);
int display_right_option(sfText *text, sfRenderWindow *window);
int display_left_option(sfText *text, sfRenderWindow *window);

#endif /* !TALK_INTERNAL_H_ */
