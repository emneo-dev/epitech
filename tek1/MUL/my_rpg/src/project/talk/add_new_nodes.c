/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** add_new_nodes
*/

#include <stdlib.h>
#include "utility.h"
#include "res.h"
#include "talk/structs.h"

static int add_no_options(talk_t *talk, new_talk_node_t *new)
{
    talk->node[new->index]->nb_options = 0;
    talk->node[new->index]->first_option = NULL;
    talk->node[new->index]->second_option = NULL;
    talk->node[new->index]->first_option_index = new->first_option_index;
    talk->node[new->index]->second_option_index = 0;
    return (0);
}

static int add_one_option(talk_t *talk, new_talk_node_t *new)
{
    talk->node[new->index]->nb_options = 1;
    talk->node[new->index]->first_option = create_text(new->first_option, 20,
                                                       talk->font, sfRed);
    talk->node[new->index]->second_option = NULL;
    sfText_setPosition(talk->node[new->index]->first_option,
                       (sfVector2f) {50, 850});
    talk->node[new->index]->first_option_index = new->first_option_index;
    talk->node[new->index]->second_option_index = 0;
    if (!talk->node[new->index]->first_option) {
        my_puterr("Could not set talk option");
        return (1);
    }
    return (0);
}

static int add_two_options(talk_t *talk, new_talk_node_t *new)
{
    talk->node[new->index]->nb_options = 2;
    talk->node[new->index]->first_option = create_text(new->first_option, 20,
                                                       talk->font, sfRed);
    talk->node[new->index]->second_option = create_text(new->second_option, 20,
                                                       talk->font, sfRed);
    sfText_setPosition(talk->node[new->index]->first_option,
                       (sfVector2f) {50, 850});
    sfText_setPosition(talk->node[new->index]->second_option,
                       (sfVector2f) {750, 850});
    talk->node[new->index]->first_option_index = new->first_option_index;
    talk->node[new->index]->second_option_index = new->second_option_index;
    if (!talk->node[new->index]->first_option ||
        !talk->node[new->index]->second_option) {
        my_puterr("Could not set talk options");
        return (1);
    }
    return (0);
}

static int handle_options(talk_t *talk, new_talk_node_t *new)
{
    switch (new->nb_options) {
    case 0:
        return (add_no_options(talk, new));
    case 1:
        return (add_one_option(talk, new));
    case 2:
        return (add_two_options(talk, new));
    default:
        my_putwarn("Too many options, none configured");
        return (add_no_options(talk, new));
    }
}

int add_new_node(talk_t *talk, new_talk_node_t *new)
{
    if (!new)
        return (1);
    talk->node[new->index] = malloc(sizeof(talk_node_t));
    if (!talk->node[new->index]) {
        my_puterr("Could not allocate new talk node!");
        return (1);
    }
    talk->node[new->index]->who_is_talking = new->who_is_talking;
    talk->node[new->index]->text = create_text(new->text, 40,
                                               talk->font, sfRed);
    sfText_setPosition(talk->node[new->index]->text, (sfVector2f) {100, 600});
    talk->node[new->index]->is_end = new->is_end;
    return (handle_options(talk, new));
}