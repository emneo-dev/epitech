/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** utility
*/

#ifndef UTILITY_H_
#define UTILITY_H_

#include <SFML/Graphics.h>

int my_puterr(char *err);
void my_putwarn(char *warn);
sfText *create_text(const char *str, int size, sfFont *font, sfColor color);

#endif /* !UTILITY_H_ */
