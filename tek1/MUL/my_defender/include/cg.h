/*
** EPITECH PROJECT, 2019
** cg.h
** File description:
** include of the cg lib
*/

#ifndef CG_H
#define CG_H

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

int cg_check_clock(sfClock *clock, float time, sfBool restart);
void cg_move_rect(sfIntRect *rect, int move, int maximum);
sfMusic *cg_load_sound(const char *path, float volume, float pitch);
sfText *cg_create_text(const char *str, int size, sfFont *font, sfColor color);
void cg_apply_gravity(sfSprite *sprite, float g_force, float *speed);
sfSprite *cg_load_sprite_form_file(char *filepath, sfTexture **texture);
sfBool cg_check_inbox(sfVector2f item, sfVector2f pos1, sfVector2f pos2);
sfVector2f cg_vchange(sfVector2f v, float x, float y);
float cg_get_distance(sfVector2f v1, sfVector2f v2);

#endif