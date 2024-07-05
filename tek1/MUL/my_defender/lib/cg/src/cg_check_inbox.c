/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** cg_check_inbox
*/

#include "SFML/Graphics.h"

sfBool cg_check_inbox(sfVector2f item, sfVector2f pos1, sfVector2f pos2)
{
    if (item.x >= pos1.x && item.x <= pos2.x &&
    item.y >= pos1.y && item.y <= pos2.y)
        return (sfTrue);
    return (sfFalse);
}