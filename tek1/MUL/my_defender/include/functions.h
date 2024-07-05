/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** functions
*/

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "core.h"
#include "menu_struct.h"

struct path *set_enemy_path(void);
enemy_t *destroy_enemy(enemy_t *enemy, enemy_t *delete);
enemy_t *follow_path(enemy_t *enemy, int *player_hp);
void tower_attack(core_t *core, enemy_t *enemy, player_t *player);

void game_loop(core_t *core, sfRenderWindow *w);
int menu_loop(menu_t *menu);
int init_core(core_t *core);

void set_tower_arrow(sfTexture *texture, tower_t *tower);
void set_tower_bomb(sfTexture *texture, tower_t *tower);
void set_tower_electric(sfTexture *texture, tower_t *tower);
void set_tower_flame(sfTexture *texture, tower_t *tower);
void set_tower_frost(sfTexture *texture, tower_t *tower);
void sell_tower(sfTexture *texture, tower_t *tower, player_t *player);

sfBool change_coin(player_t *player, int change);

void check_button_clicked(core_t *core, tower_t *selected, sfRenderWindow *w);
tower_t *check_tower_click(tower_t *t, sfVector2i mouse);

void draw_game(core_t *core, sfRenderWindow *w);
void open_build_menu(tower_t *selected, b_menu_t *menu);
void close_build_menu(b_menu_t *menu);
void event_handler(core_t *core, sfRenderWindow *w);

void init_build_menu(t_list_t *list, b_menu_t *menu);
void init_player(t_list_t *list, player_t *player);
int load_menu(sfRenderWindow *window, menu_t *menu);
enemy_t *init_enemy(core_t *core);
tower_t *create_button(tower_t *list, sfVector2f pos, sfTexture *texture);
int destroy_core(core_t *core);
void destroy_menu(menu_t *menu);

#endif /* !FUNCTIONS_H_ */
