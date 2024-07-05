/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** follow_path
*/

#include <stdlib.h>
#include "functions.h"
#include "enemy.h"
#include "cg.h"

int go_to_next_point(enemy_t *enemy)
{
    struct path *store = NULL;

    store = enemy->path->next;
    free(enemy->path);
    enemy->path = store;
    return (!enemy->path);
}

void go_to_point(enemy_t *en)
{
    sfVector2f move = {0, 0};

    if (!en->path)
        return;
    if (en->position.x < en->path->pos.x)
        move.x += en->speed;
    if (en->position.y > en->path->pos.y &&
    en->position.y - en->path->pos.y > 2)
        move.y -= en->speed;
    else if (en->position.y < en->path->pos.y)
        move.y += en->speed;
    sfSprite_move(en->sprite, move);
    en->position = sfSprite_getPosition(en->sprite);
}

enemy_t *follow_path(enemy_t *enemy, int *player_hp)
{
    enemy_t *current = enemy;

    if (!enemy)
        return (enemy);
    for (; current != NULL; current = current->next) {
        if (current->anim_cycle >= 4) {
            cg_move_rect(&current->rect, 30, 270);
            current->anim_cycle = 0;
        }
        current->anim_cycle++;
        if (cg_get_distance(current->position, current->path->pos)
        <= current->speed * 10)
            *player_hp -= go_to_next_point(current);
        if (!current->path)
            enemy = destroy_enemy(enemy, current);
        if (!enemy)
            break;
        go_to_point(current);
    }
    return (enemy);
}