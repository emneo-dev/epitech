/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** prototypes
*/

#ifndef TALK_PROTOTYPES_H_
#define TALK_PROTOTYPES_H_

#include "talk/structs.h"

talk_t *init_talk(person_t *first_person, person_t *second_person);
void destroy_talk(talk_t *talk);
int add_new_node(talk_t *talk, new_talk_node_t *new);
int launch_talk(talk_t *talk, sfRenderWindow *window);

#endif /* !TALK_PROTOTYPES_H_ */
