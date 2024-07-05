/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** change_coins
*/

#include <stdlib.h>
#include "player.h"
#include "my.h"

sfBool change_coin(player_t *player, int change)
{
    if (change < 0 && change * -1 > player->money)
        return (sfFalse);
    player->money += change;
    free(player->bal_str);
    player->bal_str = my_itoa(player->money);
    sfText_setString(player->bal_text, player->bal_str);
    return (sfTrue);
}