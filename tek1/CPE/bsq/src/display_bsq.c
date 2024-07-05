/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Display square result
*/

#include <bsq.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void display_bsq(map_t *mem, char const *path, long int highest)
{
    char the_highest = mem->mem[highest];
    struct stat sb;
    stat(path, &sb);
    char *buff = malloc(sizeof(char) * sb.st_size);
    int fd = open(path, O_RDONLY);
    get_number(fd);
    read(fd, buff, sb.st_size);
    close(fd);
    for (size_t i = 0; i < mem->size; i++)
        if (is_in_square(*mem, highest, the_highest, i))
            buff[i] = 'X';
    write(1, buff, mem->size);
    return;
}