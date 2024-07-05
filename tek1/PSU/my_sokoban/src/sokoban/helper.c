/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** helper
*/

#include "sokoban.h"

/*
*  Print the helper of the sokoban project
*/
int helper(void)
{
    put_str("USAGE\n");
    put_str("\t./my_sokoban map\n");
    put_str("DESCRIPTION\n");
    put_str("\tmap\tfile representing the warehouse map,\
    containing '#' for walls,\n");
    put_str("\t\t'P' for the player, 'X' for boxes and 'O'\
    for storage locations.\n");
    return (0);
}