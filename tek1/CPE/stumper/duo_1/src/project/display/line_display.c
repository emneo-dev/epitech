/*
** EPITECH PROJECT, 2020
** duostumper
** File description:
** line_display
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "duo.h"

static void reset_buffer(char *buffer)
{
    for (int i = 0; i < 1024; i++)
        buffer[i] = '\0';
}

int put_lines(int nb, char *buffer)
{
    int nb_seen = 0;

    for (nb_seen = 0; *buffer && nb_seen < nb; buffer++) {
        write(1, buffer, 1);
        nb_seen = (*buffer == '\n') ? nb_seen + 1 : nb_seen;
    }
    return (0);
}

char *get_line_content(int nb, int fd)
{
    char *buffer = NULL;
    char read_buffer[1024];

    while (count_lr(buffer) < nb) {
        smart_free(buffer);
        reset_buffer(read_buffer);
        read(fd, read_buffer, 1023);
        buffer = append(buffer, read_buffer);
    }
    return (buffer);
}

int line_display(int nb, char const *filepath)
{
    int fd = 0;
    char *buffer = NULL;

    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (-1);
    buffer = get_line_content(nb, fd);
    if (!buffer)
        return (-1);
    return (put_lines(nb, buffer));
}
