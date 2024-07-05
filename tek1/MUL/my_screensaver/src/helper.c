/*
** EPITECH PROJECT, 2019
** screensaver
** File description:
** Helper for the screensaver project
*/

#include "screensaver.h"

int helper(void)
{
    put_str("Animation rendering in a CSFML window\n\
         \n\
        USAGE\n\
         ./my_screensaver [OPTIONS] animation_id\n\
         animation_id     ID of the animation to process (Between 1 and 3)\n\
         \n\
        OPTIONS\n\
         -d               print the description of the animations and quit\n\
         -h               print the usage and quit\n");
    return (0);
}
