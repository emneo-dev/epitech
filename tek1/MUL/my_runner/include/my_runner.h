/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_runner
*/

#ifndef MY_RUNNER_H_
#define MY_RUNNER_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

/*
*  Structures
*/

typedef struct player_s {
    sfSprite *sprite;
    double speed;
    sfTexture *texture;
    sfIntRect rect;
    sfClock *clock;
} player_t;

typedef struct parralax_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfSprite *sprite_2;
    sfTexture *texture_2;
    struct parralax_s *next;
} parralax_t;

typedef struct map_s {
    sfSprite *top;
    sfSprite *bottom;
    sfTexture *top_tex;
    sfTexture *bottom_tex;
    struct map_s *next;
} map_t;

typedef struct game_object_s {
    sfRenderWindow *window;
    player_t *player;
    parralax_t *parralax;
    map_t *map;
    sfSound *jump;
    sfSoundBuffer *jump_buff;
    sfMusic *music;
    sfText *score;
    sfClock *g_clock;
    sfFont *my_font;
    int is_won;
} game_object_t;

/*
*  Function prototypes
*/

int my_runner(char const **argv);
void handle_events(game_object_t *objects);
void handle_key_pressed(game_object_t *objects);
void wait_for_input(game_object_t *objects);
int helper(void);
int is_won(game_object_t *objects);
void final_screen(game_object_t *objects);

// Initialization

sfRenderWindow *init_window(char const *name, sfVector2u size);
game_object_t *init_game_objects(char const *name);
player_t *init_player(void);
parralax_t *init_parralax(void);
map_t *init_map(char const *filepath);
void init_sound(game_object_t *objects);
void init_score(game_object_t *objects);

// Display

void display_objects(game_object_t *objects);
void display_player(game_object_t *objects);
void display_parralax(game_object_t *objects, long double speed);
void display_map(game_object_t *objects);
void display_score(game_object_t *objects);

// Destroy

void destroy_game_objects(game_object_t *objects);
void destroy_player(player_t *player);
void destroy_parralax(parralax_t *parralax);
void destroy_map(map_t *map);
void destroy_sound(game_object_t *objects);
void destroy_score(game_object_t *objects);

// Physics

void apply_gravity(player_t *player, double g_force);
int is_sprite_colliding(sfSprite *a, sfSprite *b);
int check_collisions(game_object_t *objects);

// Sound

void sound_jump(game_object_t *objects);

// Utility

char *get_next_line(int fd);
char *int_to_string(long long int nb);

/*
*  Defines
*/

#define SPACE "./res/space.png"
#define PLAYER_FILE "./res/player.png"
#define P_1 "./res/1.png"
#define P_2 "./res/2.png"
#define P_3 "./res/3.png"
#define P_4 "./res/4.png"
#define P_5 "./res/5.png"
#define P_6 "./res/6.png"
#define P_7 "./res/7.png"
#define BUIL "./res/building.png"
#define JMP_F "./res/jump_sound.ogg"
#define MUS_F "./res/music.ogg"
#define TYP "./res/font.ttf"
#define LEN_OB 300
#define JUMP_FORCE -7
#define SPEED_SCROLL 5
#define READ_SIZE 1024

#endif /* !MY_RUNNER_H_ */