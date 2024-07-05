/*
** EPITECH PROJECT, 2019
** libcorn
** File description:
** corn_check_clock
*/

#include <SFML/System.h>

/**
* \file corn_check_clock.c
* \author Alexandre Descoins
* \version 1
*/
int corn_check_clock(sfClock *clock, float time, sfBool restart)
{
    sfTime clock_time = sfClock_getElapsedTime(clock);
    float f_time = sfTime_asSeconds(clock_time);

    if (f_time > time) {
        if (restart == sfTrue)
            sfClock_restart(clock);
        return (1);
    }
    return (0);
}