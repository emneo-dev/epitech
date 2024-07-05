/*
** EPITECH PROJECT, 2019
** screensaver
** File description:
** Entry point of screensaver
*/

#include "seal.h"
#include "screensaver.h"

framebuffer_t * (*scr_sv[])(framebuffer_t *buff) = {
    scr1,
    scr2,
    scr3
};

static int handle_args(char *arg)
{
    if (my_strcmp(arg, "-h"))
        return (helper());
    return (anim_desc());
}

int screensaver(int argc, char **argv)
{
    if (argc != 2)
        return (84);
    if (!(my_strcmp(argv[1], "-h")) || !(my_strcmp(argv[1], "-d")))
        return (handle_args(argv[1]));
    else if (argv[1][0] > 48 && argv[1][0] < 52 && !argv[1][1])
        return (sl_play((void *) argv[1]));
    return (84);
}

framebuffer_t *init(framebuffer_t *buff, void *to_pass)
{
    to_pass = to_pass;

    return (buff);
}

framebuffer_t *loop(framebuffer_t *buff, void *to_pass)
{
    char *id = (char *)(to_pass);
    if (id[0] > 48 && id[0] < 53 && !id[1])
        return (scr_sv[id[0] - 49](buff));
    return (NULL);
}
