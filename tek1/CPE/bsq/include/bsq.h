/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Header file for BSQ
*/

#ifndef BSQ_H
#define BSQ_H

#include <stdlib.h>

typedef struct map {
    int row;
    int columns;
    char *mem;
    size_t size;
} map_t;

typedef struct fnb {
    int number;
    int length;
} fnb_t;

typedef struct vector2 {
    int x;
    int y;
} vector2_t;

map_t load_file_to_mem(char const *path);
fnb_t get_number(int fd);
int is_upper_side(map_t mem, long int index);
int is_left_side(map_t mem, long int index);
void my_set_value(map_t *mem, long int index);
void loop_value(map_t *mem);
char get_shortest(char a, char b, char c);
size_t get_highest(map_t mem);
vector2_t convert_to_v2(map_t mem, long int index);
void display_bsq(map_t *mem, char const *path, long int highest);
int is_in_square(map_t mem, long int highest, char the_highest, long int index);

#endif /* BSQ_H */
