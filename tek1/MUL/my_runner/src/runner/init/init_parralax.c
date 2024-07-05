/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019 [WSL: Debian]
** File description:
** init_parralax
*/

#include <stdlib.h>
#include "my_runner.h"
#include "corn.h"

static int create_node(char const *filepath, parralax_t **current)
{
    parralax_t *new = NULL;

    new = malloc(sizeof(parralax_t));
    new->sprite = corn_load_sprite_from_file(filepath, &new->texture);
    sfSprite_setScale(new->sprite, (sfVector2f) {3, 3});
    new->sprite_2 = corn_load_sprite_from_file(filepath, &new->texture_2);
    sfSprite_setScale(new->sprite_2, (sfVector2f) {3, 3});
    sfSprite_setPosition(new->sprite_2, (sfVector2f) {1152, 0});
    new->next = *current;
    *current = new;
    return (0);
}

parralax_t *init_parralax(void)
{
    parralax_t *current = NULL;

    create_node(P_1, &current);
    create_node(P_2, &current);
    create_node(P_3, &current);
    create_node(P_4, &current);
    create_node(P_5, &current);
    create_node(P_6, &current);
    create_node(P_7, &current);
    return (current);
}