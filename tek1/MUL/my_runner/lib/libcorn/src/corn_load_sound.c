/*
** EPITECH PROJECT, 2019
** libcorn
** File description:
** corn_load_sound
*/

#include <SFML/System.h>
#include <SFML/Audio.h>
#include <unistd.h>

static void corn_write_error(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        write(2, &str[i], 1);
}

/**
* \file corn_load_sound.c
* \author Alexandre Descoins
* \version 1
*/
sfMusic *corn_load_sound(const char *path, float volume, float pitch)
{
    sfMusic *music = sfMusic_createFromFile(path);

    if (music == NULL) {
        corn_write_error("File \"");
        corn_write_error(path);
        corn_write_error("\" could not load\n");
        return (NULL);
    }
    sfMusic_setVolume(music, volume);
    sfMusic_setPitch(music, pitch);
    return (music);
}