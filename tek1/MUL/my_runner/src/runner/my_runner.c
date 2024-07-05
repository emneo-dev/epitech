/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_runner
*/

#include <SFML/Graphics.h>
#include "my.h"
#include "corn.h"
#include "my_runner.h"

int my_runner(char const **argv)
{
    game_object_t *objects = NULL;

    objects = init_game_objects(argv[1]);
    if (!objects)
        return (84);
    wait_for_input(objects);
    while (sfRenderWindow_isOpen(objects->window)) {
        sfRenderWindow_clear(objects->window, sfBlack);
        handle_events(objects);
        sfRenderWindow_display(objects->window);
        if (is_won(objects)) {
            final_screen(objects);
            sfRenderWindow_close(objects->window);
        }
    }
    destroy_game_objects(objects);
    return (0);
}