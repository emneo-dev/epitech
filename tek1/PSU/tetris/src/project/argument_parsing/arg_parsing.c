/*
** EPITECH PROJECT, 2020
** PSU_tetris
** File description:
** arg_parsing
*/

#include <stdio.h>
#include <getopt.h>
#include "my.h"
#include "struct.h"

static void switch_key(int c, args_t *args)
{
    switch (c) {
        case 'l':
            args->key_left = optarg[0];
            break;
        case 'r':
            args->key_right = optarg[0];
            break;
        case 't':
            args->key_turn = optarg[0];
            break;
        case 'd':
            args->key_drop = optarg[0];
            break;
        case 'q':
            args->key_quit = optarg[0];
            break;
        case 'p':
            args->key_pause = optarg[0];
            break;
    }
}

static void switch_setting(int c, args_t *args)
{
    switch (c) {
        case 'h':
            args->help = 1;
            break;
        case 'L':
            args->level = my_getnbr(optarg);
            break;
        case 'm':
            free(args->map_size);
            args->map_size = malloc(sizeof(char) * (my_strlen(optarg) + 1));
            my_strcpy(args->map_size, optarg);
            break;
        case 'w':
            args->without_next = 1;
            break;
        case 'D':
            args->debug = 1;
            break;
        }
}

static void setup_key(int argc, char **argv, args_t *args,
struct option *long_options)
{
    int c = 0;
    int option_index = 0;

    while ((c = getopt_long(argc, argv, "hL:l:r:t:d:q:p:m:wD", long_options,
    &option_index)) != -1) {
        switch_key(c, args);
        switch_setting(c, args);
    }
}

args_t *arg_parsing(int argc, char **argv, args_t *args)
{
    static struct option long_options[] = {
        {"help", no_argument, 0, 'h'},
        {"level", required_argument, 0, 'L'},
        {"key-left", required_argument, 0, 'l'},
        {"key-right", required_argument, 0, 'r'},
        {"key-turn", required_argument, 0, 't'},
        {"key-drop", required_argument, 0, 'd'},
        {"key-quit", required_argument, 0, 'q'},
        {"key-pause", required_argument, 0, 'p'},
        {"map-size", required_argument, 0, 'm'},
        {"without-next", no_argument, 0, 'w'},
        {"debug", no_argument, 0, 'D'},
        {0, 0, 0, 0}
    };
    setup_key(argc, argv, args, long_options);
    if (!args)
        return (NULL);
    return (args);
}