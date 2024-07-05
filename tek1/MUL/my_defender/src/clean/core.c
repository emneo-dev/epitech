/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** core
*/

#include "core.h"

void clean_textures(t_list_t *list)
{
    sfTexture_destroy(list->arrow);
    sfTexture_destroy(list->background);
    sfTexture_destroy(list->bomb);
    sfTexture_destroy(list->build_button);
    sfTexture_destroy(list->coin);
    sfTexture_destroy(list->fire);
    sfTexture_destroy(list->ice);
    sfTexture_destroy(list->knight);
    sfTexture_destroy(list->map);
    sfTexture_destroy(list->sell);
    sfTexture_destroy(list->thunder);
    sfTexture_destroy(list->tower_arrow);
    sfTexture_destroy(list->tower_bomb);
    sfTexture_destroy(list->tower_elec);
    sfTexture_destroy(list->tower_fire);
    sfTexture_destroy(list->tower_ice);
    sfTexture_destroy(list->upgrade);
}

void clean_core(core_t *core)
{
    clean_textures(core->t_list);
    free(core->t_list);
    sfMusic_destroy(core->ambient);
    clean_build_menu(core->build_menu);
    free(core->build_menu);
    free(core->clicked);
    sfClock_destroy(core->clock);
    free(core->data);
}