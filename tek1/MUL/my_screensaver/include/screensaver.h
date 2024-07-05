/*
** EPITECH PROJECT, 2019
** srceensaver
** File description:
** Header file for screensaver
*/

#ifndef SV_H
#define SV_H

#include "seal.h"

int screensaver(int argc, char **argv);
int put_str(char *str);
int helper(void);
int anim_desc(void);
int my_strcmp(char const *s1, char const *s2);
framebuffer_t *scr1(framebuffer_t *buff);
framebuffer_t *scr2(framebuffer_t *buff);
framebuffer_t *scr3(framebuffer_t *buff);

#endif /* SV_H */
