/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Header file containing all structures
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct args_s {
    int help;
    int level;
    char key_left;
    char key_right;
    char key_turn;
    char key_drop;
    char key_quit;
    char key_pause;
    char *map_size;
    int without_next;
    int debug;
} args_t;

typedef struct tetr_s {
    char **normal;
    char **down;
    char **left;
    char **right;
    char *name;
    int width;
    int height;
    int color;
    struct tetr_s *next;
} tetr_t;

#endif /* !STRUCT_H_ */
