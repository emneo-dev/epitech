/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** destroy_core
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "core.h"

static void destroy_texture_list(t_list_t *list)
{
    sfTexture_destroy(list->build_button);
    sfTexture_destroy(list->bomb);
    sfTexture_destroy(list->tower_bomb);
    sfTexture_destroy(list->ice);
    sfTexture_destroy(list->tower_ice);
    sfTexture_destroy(list->fire);
    sfTexture_destroy(list->tower_fire);
    sfTexture_destroy(list->thunder);
    sfTexture_destroy(list->tower_elec);
    sfTexture_destroy(list->arrow);
    sfTexture_destroy(list->tower_arrow);
    sfTexture_destroy(list->knight);
    sfTexture_destroy(list->sell);
    sfTexture_destroy(list->upgrade);
    sfTexture_destroy(list->coin);
    sfTexture_destroy(list->map);
}

static void destroy_enemy(enemy_t *enemy)
{
    struct path *cur = NULL;
    enemy_t *next = NULL;

    while (enemy) {
        next = enemy->next;
        sfSprite_destroy(enemy->sprite);
        cur = enemy->path;
        while (enemy->path) {
            cur = enemy->path->next;
            free(enemy->path);
            enemy->path = cur;
        }
        free(enemy);
        enemy = next;
    }
}

static void destroy_b_menu(b_menu_t *menu)
{
    sfSprite_destroy(menu->bomb);
    sfSprite_destroy(menu->fire);
    sfSprite_destroy(menu->ice);
    sfSprite_destroy(menu->thunder);
    sfSprite_destroy(menu->arrow);
    sfSprite_destroy(menu->sell);
    sfSprite_destroy(menu->upgrade);
}

static void destroy_tower(tower_t *tower)
{
    tower_t *next = NULL;

    while (tower) {
        next = tower->next;
        sfSprite_destroy(tower->sprite);
        sfClock_destroy(tower->attack);
        free(tower);
        tower = next;
    }
}

int destroy_core(core_t *core)
{
    sfMusic_destroy(core->ambient);
    sfRenderWindow_destroy(core->window);
    free(core->wave_stock);
    sfText_destroy(core->wave_text);
    sfClock_destroy(core->spawn);
    sfClock_destroy(core->clock);
    sfSprite_destroy(core->map);
    sfCircleShape_destroy(core->tow_range);
    destroy_texture_list(&core->t_list);
    sfText_destroy(core->player.bal_text);
    sfFont_destroy(core->player.stat_font);
    free(core->player.bal_str);
    sfSprite_destroy(core->player.coin);
    destroy_enemy(core->enemy);
    destroy_b_menu(&core->build_menu);
    destroy_tower(core->towers);
    destroy_tower(core->clicked);
    return (0);
}
