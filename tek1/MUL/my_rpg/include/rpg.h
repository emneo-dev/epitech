/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Header file for the my_rpg project
*/

#ifndef RPG_H_
#define RPG_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

typedef struct {
    sfRenderWindow *window;
} core_t;

typedef struct {
    sfTexture *texture;
    int nb_of_slot;
} inventory_t;

typedef struct game_object {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f move;
    sfIntRect *hitbox;
} game_object_t;

typedef struct manage_menu {
    game_object_t *background;
    game_object_t *background2;
    game_object_t *button_play;
    game_object_t *button_quit;
    game_object_t *back;
    game_object_t *coin;
    sfSound *song;
    sfTime time;
    sfSoundBuffer *soundBuffer;
}m_menu;

int rpg(void);
int base_init(core_t *core);
sfRenderWindow *init_window(char const *name, sfVector2u size);
void base_event_handler(core_t *core);
void destroy_core(core_t *core);

// Inventory
int display_inventory(inventory_t *inventory, sfRenderWindow *window);
int initialize_inventory(inventory_t *inventory, char *path);

// Menu
game_object_t *create_object (char *, int, int);
void init_hitbox(game_object_t *);
void move_coin(m_menu *menu);
void destroy_object(game_object_t *);
sfBool button_pressed(game_object_t *, sfRenderWindow *window);
sfBool is_mouse_on_object(game_object_t *, sfRenderWindow *window);
int init_texture_menu(m_menu *menu);
void display_menu(sfRenderWindow *window, m_menu *menu);
int m_button_menu(m_menu *menu, sfRenderWindow *window);

#endif /* !RPG_H_ */
