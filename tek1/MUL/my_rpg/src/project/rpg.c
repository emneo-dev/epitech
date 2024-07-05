/*
** EPITECH PROJECT, 2020
** sample_project
** File description:
** sample
*/

#include <stdlib.h>
#include <stdio.h>
#include "utility.h"
#include "talk/prototypes.h"
#include "movement/prototypes.h"
#include "rpg.h"

// This function can be used to test the features
int rpg(void)
{
    inventory_t inventory;
    core_t core;
    player_t player;
    map_t map;
    m_menu menu;
    sfEvent event;
    int scene = 0;

    if (base_init(&core))
        return (84);
    init_texture_menu(&menu);
    while (!scene && sfRenderWindow_isOpen(core.window)) {
        while (sfRenderWindow_pollEvent(core.window, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(core.window);
        display_menu(core.window, &menu);
        scene = m_button_menu(&menu, core.window);
    }
    if (scene == 2)
        sfRenderWindow_close(core.window);
    initialize_inventory(&inventory, "./res/img/inv.png");
    init_player(&player, "./res/img/perso.png", &inventory);
    init_map(&map, &(new_map_t) {(sfVector2f) {500, 500},
        (sfVector2f) {791, 575}, (sfVector2f) {200, 200},
        "./res/img/map_0.png"}, &player);
    talk_t *talk = init_talk(&(person_t) {NULL, NULL},
                             &(person_t) {NULL, NULL});
    add_new_node(talk, &(new_talk_node_t) {0, 0, 1, "text bad", NULL, NULL,
                                           1, 2, 0});
    add_new_node(talk, &(new_talk_node_t) {1, 1, 1, "text good", "NULL", NULL,
                                           2, 2, 0});
    add_new_node(talk, &(new_talk_node_t) {2, 2, 1, "text good ?", "NULL lmao",
                                           "not NULL", 1, 3, 0});
    add_new_node(talk, &(new_talk_node_t) {3, 0, 1, "end", NULL, NULL,
                                           15, 2, 1});
    add_event_node(&map, (map_evt_t) {0, 20, (sfVector2f) {200, 200},
                                    (void *) talk, NULL});
    add_event_node(&map, (map_evt_t) {1, 20, (sfVector2f) {500, 200},
                                    (void *) 42, NULL});
    display_map(&map, core.window);
    sfRenderWindow_destroy(core.window);
    return (0);
}