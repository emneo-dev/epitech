/*
** EPITECH PROJECT, 2019
** libcorn
** File description:
** corn.h
*/

#ifndef CORN_H
#define CORN_H

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

/**
* \fn int corn_check_clock(sfClock *clock, float time, sfBool restart);
* \brief check if the clock went past the given time in second
* \param clock a clock that is already running
* \param time time in second
* \param restart Shoud the clock be restarted if it return 1 ?
* \return int 1 if the elapsed time is > or = to time eitherway it will return 0
*/
int corn_check_clock(sfClock *clock, float time, sfBool restart);

/**
* \fn void corn_move_rect(sfIntRect *rect, int move, int maximum);
* \brief move a rect to the left by a given value
* \param rect The sfRect to be moved
* \param move The value of wich the rect will be moved to the left
* \param maximum The left value of the rect, reset the rect if his left is higher than it
*/
void corn_move_rect(sfIntRect *rect, int move, int maximum);


sfMusic *corn_load_sound(const char *path, float volume, float pitch);


sfText *corn_create_text(const char *str, int size, sfFont *font, sfColor color);


void corn_apply_gravity(sfSprite *sprite, float g_force, float *speed);


sfSprite *corn_load_sprite_from_file(char const *filepath, sfTexture **texture);

#endif