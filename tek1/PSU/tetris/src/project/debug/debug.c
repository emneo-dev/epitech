/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** debug
*/

#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include "my.h"
#include "struct.h"
#include "prototype.h"

static void disp_total_tetr(tetr_t *tetr)
{
    int i = 0;

    my_putstr("\nTetriminos : ");
    for (i = 0; tetr; tetr = tetr->next, i++);
    my_put_nbr(i);
    my_putchar('\n');
}

static void disp_tetr(tetr_t *tetr)
{
    disp_total_tetr(tetr);
    for (; tetr != NULL; tetr = tetr->next) {
        my_putstr("Tetriminos : Name ");
        write(1, tetr->name, my_strlen(tetr->name) - 10);
        my_putstr(" : Size ");
        my_put_nbr(tetr->width);
        my_putchar('*');
        my_put_nbr(tetr->height);
        my_putstr(" : Color ");
        my_put_nbr(tetr->color);
        my_putstr(" :\n");
        for (int i = 0; i < tetr->height; i++) {
            write(1, tetr->normal[i], tetr->width);
            my_putchar('\n');
        }
    }
}

static void disp_key(char key)
{
    switch (key) {
    case -1:
        my_putstr("^EOD");
        break;
    case -2:
        my_putstr("^EOC");
        break;
    case -3:
        my_putstr("^EOA");
        break;
    case -4:
        my_putstr("^EOB");
        break;
    case ' ':
        my_putstr("(space)");
        break;
    default:
        my_putchar(key);
        break;
    }
}

static void display_key(args_t *args)
{
    disp_key(args->key_left);
    my_putstr("\nKey Right : ");
    disp_key(args->key_right);
    my_putstr("\nKey Turn : ");
    disp_key(args->key_turn);
    my_putstr("\nKey Drop : ");
    disp_key(args->key_drop);
    my_putstr("\nKey Quit : ");
    disp_key(args->key_quit);
    my_putstr("\nKey Pause : ");
    disp_key(args->key_pause);
}

int debug(args_t *args, tetr_t *tetr)
{
    my_putstr("*** DEBUG MODE ***\nKey Left : ");
    display_key(args);
    if (args->without_next)
        my_putstr("\nNext : No\n");
    else
        my_putstr("\nNext : Yes\n");
    my_putstr("Level : ");
    my_put_nbr(args->level);
    my_putstr("\nSize : ");
    my_putstr(args->map_size);
    disp_tetr(tetr);
    my_putstr("Press any key to start Tetris\n");
    return (game(args, tetr));
}