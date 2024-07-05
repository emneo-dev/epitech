/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** attack
*/

#include "core.h"
#include "cg.h"
#include "functions.h"

void tower_attack(core_t *core, enemy_t *enemy, player_t *player)
{
    enemy_t *en = enemy;
    tower_t *towers = core->towers;

    if (!enemy)
        return;
    for (tower_t *list = towers; list; list = list->next) {
        if (!cg_check_clock(list->attack, list->speed, sfTrue))
            break;
        for (; en && cg_get_distance
        (list->position, en->position) >= list->range; en = en->next);
        if (en)
            en->health -= list->damages;
        if (en && en->health <= 0) {
            change_coin(player, en->value);
            enemy = destroy_enemy(enemy, en);
        }
        en = enemy;
    }
    core->enemy = enemy;
}