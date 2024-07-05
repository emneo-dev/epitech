/*
** EPITECH PROJECT, 2019
** cg_check_clock.c
** File description:
** Check a clock
*/

#include <SFML/System.h>
#include <SFML/Audio.h>
#include <unistd.h>

static void cg_write_error(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        write(2, &str[i], 1);
}

sfMusic *cg_load_sound(const char *path, float volume, float pitch)
{
    sfMusic *music = sfMusic_createFromFile(path);

    if (music == NULL) {
        cg_write_error("File \"");
        cg_write_error(path);
        cg_write_error("\" could not load\n");
        return (NULL);
    }
    sfMusic_setVolume(music, volume);
    sfMusic_setPitch(music, pitch);
    return (music);
}