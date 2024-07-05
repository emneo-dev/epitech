/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** main
*/

#include "SFML/Graphics.h"
#include "menu_struct.h"
#include "core.h"
#include "cg.h"
#include "functions.h"

static int init_window(sfRenderWindow **window, char const *name)
{
    sfVideoMode mode = {1280, 720, 32};

    *window = sfRenderWindow_create(mode, name, sfClose, NULL);
    if (!*window)
        return (-1);
    sfRenderWindow_setFramerateLimit(*window, 60);
    sfRenderWindow_setKeyRepeatEnabled(*window, sfFalse);
    return (0);
}

static int base_init(core_t *core, menu_t *menu)
{
    init_core(core);
    if (init_window(&core->window, "my_defender"))
        return (-1);
    load_menu(core->window, menu);
    return (0);
}

int main(void)
{
    core_t core;
    menu_t menu;

    if (base_init(&core, &menu))
        return (84);
    if (menu_loop(&menu) == -1) {
        destroy_menu(&menu);
        return (destroy_core(&core));
    }
    destroy_menu(&menu);
    sfMusic_play(core.ambient);
    while (sfRenderWindow_isOpen(core.window))
        game_loop(&core, core.window);
    sfMusic_stop(core.ambient);
    return (destroy_core(&core));
}
