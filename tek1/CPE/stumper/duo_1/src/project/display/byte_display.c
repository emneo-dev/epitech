/*
** EPITECH PROJECT, 2020
** duostumper
** File description:
** byte_display
*/

#include <unistd.h>
#include <fcntl.h>
#include "my.h"

int byte_display(int nb, char const *filepath)
{
    int fd = 0;
    char *buffer;

    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (1);
    buffer = malloc(sizeof(char) * (nb + 1));
    if (!buffer)
        return (1);
    if (read(fd, buffer, nb) == -1)
        return (1);
    buffer[nb] = '\0';
    my_putstr(buffer);
    free(buffer);
    return (0);
}
