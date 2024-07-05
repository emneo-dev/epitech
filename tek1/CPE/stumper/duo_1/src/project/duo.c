/*
** EPITECH PROJECT, 2020
** duostumper
** File description:
** duo
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"
#include "duo.h"

void paths_check(paths_t *path, int *return_value)
{
    int fd = 0;

    while (path) {
        fd = open(path->str, O_RDONLY);
        if (fd == -1)
            *return_value = 1;
        else
            close(fd);
        path = path->next;
    }
}

int print_head(args_t *args)
{
    int return_value = 0;

    paths_check(args->paths, &return_value);
    if (args->c)
        for (int i = 0; i < args->paths_len; i++,
                args->paths = args->paths->next)
            byte_display(args->c, args->paths->str);
    else
        for (int i = 0; i < args->paths_len; i++,
                args->paths = args->paths->next)
            line_display(args->n, args->paths->str);
    return (return_value);
}

int duo(int argc, char const **argv)
{
    args_t *args = NULL;

    args = arg_parsing(argc, argv);
    return (print_head(args));
}
