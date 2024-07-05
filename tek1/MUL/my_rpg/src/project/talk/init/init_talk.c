/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** init_talk
*/

#include <stdlib.h>
#include "talk/structs.h"
#include "talk/internal.h"
#include "utility.h"
#include "res.h"

// Sets the talk stucture components to NULL
static void base_talk_init(talk_t *talk)
{
    talk->left_name = NULL;
    talk->left_sprite = NULL;
    talk->node = NULL;
    talk->right_name = NULL;
    talk->right_sprite = NULL;
    talk->font = NULL;
}

talk_t *init_talk(person_t *first_person, person_t *second_person)
{
    talk_t *talk = NULL;

    talk = malloc(sizeof(talk_t));
    if (!talk)
        return (NULL);
    base_talk_init(talk);
    if (init_font(talk, FIRA_SANS_FONT))
        return (NULL);
    first_person_init(talk, first_person);
    second_person_init(talk, second_person);
    if (init_nodes(talk))
        return (NULL);
    return (talk);
}