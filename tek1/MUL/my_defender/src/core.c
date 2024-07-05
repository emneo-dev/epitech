/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** core
*/

#include <stdlib.h>
#include "core.h"
#include "build_menu.h"
#include "functions.h"
#include "cg.h"

static void init_textures(t_list_t *list)
{
    list->build_button = sfTexture_createFromFile("res/sprites/build.png",
        NULL);
    list->fire = sfTexture_createFromFile("res/sprites/fire.png", NULL);
    list->tower_fire = sfTexture_createFromFile("res/sprites/flame.png", NULL);
    list->ice = sfTexture_createFromFile("res/sprites/ice.png", NULL);
    list->tower_ice = sfTexture_createFromFile("res/sprites/frost.png", NULL);
    list->bomb = sfTexture_createFromFile("res/sprites/bomb.png", NULL);
    list->tower_bomb = sfTexture_createFromFile("res/sprites/mortar.png", NULL);
    list->map = sfTexture_createFromFile("res/sprites/map.png", NULL);
    list->thunder = sfTexture_createFromFile("res/sprites/thunder.png", NULL);
    list->tower_elec = sfTexture_createFromFile("res/sprites/tesla.png", NULL);
    list->arrow = sfTexture_createFromFile("res/sprites/arrow.png", NULL);
    list->tower_arrow = sfTexture_createFromFile("res/sprites/balista.png",
        NULL);
    list->sell = sfTexture_createFromFile("res/sprites/sell.png", NULL);
    list->upgrade = sfTexture_createFromFile("res/sprites/upgrade.png", NULL);
    list->coin = sfTexture_createFromFile("res/sprites/coin.png", NULL);
    list->knight = sfTexture_createFromFile("res/sprites/knight.png", NULL);
}

static sfCircleShape *init_tower_range(void)
{
    sfCircleShape *new = sfCircleShape_create();

    sfCircleShape_setFillColor(new, (sfColor){119, 239, 247, 25});
    sfCircleShape_setOutlineThickness(new, 1);
    sfCircleShape_setOutlineColor(new, (sfColor){41, 216, 255, 255});
    return (new);
}

static void init_wave(core_var_t *data)
{
    data->wave = 0;
    data->enemy_left = 0;
    data->next_spawn = 0;
    data->status = RUNNING;
}

static tower_t *init_buttons(t_list_t *textures)
{
    tower_t *tow = NULL;

    tow = create_button(tow, (sfVector2f){245, 330}, textures->build_button);
    create_button(tow, (sfVector2f){380, 330}, textures->build_button);
    create_button(tow, (sfVector2f){380, 450}, textures->build_button);
    return (tow);
}

int init_core(core_t *core)
{
    init_textures(&core->t_list);
    core->towers = init_buttons(&core->t_list);
    core->map = sfSprite_create();
    sfSprite_setTexture(core->map, core->t_list.map, sfFalse);
    init_player(&core->t_list, &core->player);
    core->clicked = NULL;
    init_build_menu(&core->t_list, &core->build_menu);
    core->clock = sfClock_create();
    core->enemy = NULL;
    core->tow_range = init_tower_range();
    init_wave(&core->data);
    core->wave_text = cg_create_text("0", 120, core->player.stat_font, sfGreen);
    core->ambient = sfMusic_createFromFile("res/audio/battle.ogg");
    sfText_setPosition(core->wave_text, (sfVector2f){-300, 720 / 2 - 120});
    core->spawn = sfClock_create();
    core->wave_stock = NULL;
    sfMusic_setLoop(core->ambient, sfTrue);
    return (0);
}
