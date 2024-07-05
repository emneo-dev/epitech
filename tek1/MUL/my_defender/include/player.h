/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** player
*/

#ifndef PLAYER_H_
#define PLAYER_H_

#include <SFML/Graphics.h>

typedef struct player_s {
    int health;
    int money;
    char *bal_str;
    sfText *bal_text;
    sfFont *stat_font;
    sfSprite *coin;
}player_t;

#endif /* !PLAYER_H_ */