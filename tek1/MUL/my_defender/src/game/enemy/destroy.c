/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** destroy
*/

#include <stdlib.h>
#include "enemy.h"

enemy_t *destroy_enemy(enemy_t *enemy, enemy_t *delete)
{
    struct path *cur = NULL;
    enemy_t *save = enemy;
    enemy_t *stock = enemy;

    sfSprite_destroy(delete->sprite);
    while (delete->path) {
        cur = delete->path->next;
        free(delete->path);
        delete->path = cur;
    }
    if (enemy == delete) {
        save = enemy->next;
        free(enemy);
        enemy = save;
        return (save);
    }
    for(; stock->next != delete && stock->next; stock = stock->next);
    save = delete->next;
    stock->next = save;
    free(delete);
    return (enemy);
}
