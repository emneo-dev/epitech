/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019 [WSL: Debian]
** File description:
** apply_gravity
*/

#include "my_runner.h"

void apply_gravity(player_t *player, double g_force)
{
    player->speed += (g_force / 60);
}