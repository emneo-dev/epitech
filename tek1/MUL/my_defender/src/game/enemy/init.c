/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** init
*/

#include <stdlib.h>
#include "functions.h"
#include "core.h"
#include "cg.h"

static void set_enemy_props(enemy_t *new, core_t *core)
{
    new->sprite = cg_load_sprite_form_file(NULL, &core->t_list.knight);
    new->health = 50;
    new->rect = (sfIntRect){0, 0, 30, 36};
    new->speed = 1.6f;
    new->value = 20;
    new->anim_cycle = 0;
    new->next = NULL;
    new->path = set_enemy_path();
    new->position = (sfVector2f){-50, 550};
}

enemy_t *init_enemy(core_t *core)
{
    enemy_t *new = malloc(sizeof(enemy_t));
    enemy_t *last = core->enemy;

    if (new == NULL)
        return (NULL);
    set_enemy_props(new, core);
    sfSprite_setPosition(new->sprite, new->position);
    if (!last)
        return (new);
    for (; last->next != NULL; last = last->next);
    core->data.next_spawn =
    (float)rand()/(float)(RAND_MAX) * 3.0f + 0.4f;
    new->gbound = sfSprite_getGlobalBounds(new->sprite);
    last->next = new;
    return (core->enemy);
}
