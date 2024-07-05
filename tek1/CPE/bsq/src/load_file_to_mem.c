/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Load a file to memory
*/

#include <bsq.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

map_t load_file_to_mem(char const *path)
{
    struct stat sb;
    map_t ret;
    stat(path, &sb);
    char *buff = malloc(sizeof(char) * sb.st_size);
    int fd = open(path, O_RDONLY);
    fnb_t info = get_number(fd);
    read(fd, buff, sb.st_size);
    ret.mem = buff;
    ret.row = info.number;
    ret.columns = ((sb.st_size) - (info.length + 1) - ret.row) / ret.row;
    ret.size = sb.st_size;
    return (ret);
}
