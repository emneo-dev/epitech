/*
** EPITECH PROJECT, 2020
** duostumper
** File description:
** duo
*/

#ifndef DUO_H
#define DUO_H

//
// Structures
//

typedef struct paths_s {
    char *str;
    struct paths_s *next;
} paths_t;

typedef struct args_s{
    int c;
    int n;
    int q;
    int v;
    int paths_len;
    paths_t *paths;
} args_t;

//
// Prototypes
//

int duo(int argc, char const **argv);

// Display

int byte_display(int nb, char const *filepath);
int line_display(int nb, char const *filepath);
int put_lines(int nb, char *buffer);

// Utilities

int count_lr(char const *str);
char *append(char *first, char *second);
void smart_free(void *ptr);

// Parsing

args_t *arg_parsing(int argc, char const **argv);

#endif /* DUO_H */
