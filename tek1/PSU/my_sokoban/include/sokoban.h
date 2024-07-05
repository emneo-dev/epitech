/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** sokoban
*/

#ifndef SOKOBAN_H
#define SOKOBAN_H

typedef struct vector2d_s {
    int x;
    int y;
} vector2d_t;

/*
*  Node for linked list containing :
*   vector2d_t position;
*   int priority;
*   char display;
*   struct o_link_s *next;
*/
typedef struct o_link_s {
    vector2d_t position;
    int priority;
    char display;
    struct o_link_s *next;
} o_link_t;

int sokoban(int argc, char **argv);
int helper(void);
int my_strlen(char *str);
int put_str(char *str);
int my_strcmp(char const *s1, char const *s2);
o_link_t *load_map(char *path);
int main_loop(o_link_t *map);
int event_handler(o_link_t *map);
void display_map(o_link_t *map);
vector2d_t get_player_location(o_link_t *map);
o_link_t *get_player_node(o_link_t *map);
o_link_t *get_dest(vector2d_t pos, o_link_t *map);
int is_won(o_link_t *map);

//Movements functions

int move_up(o_link_t *map);
int move_down(o_link_t *map);
int move_right(o_link_t *map);
int move_left(o_link_t *map);

#endif /* SOKOBAN_H */