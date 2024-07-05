/*
** EPITECH PROJECT, 2019
** BSQ_bootstrap
** File description:
** Display x bytes from a file descriptor
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void fs_cat_x_bytes(char const *filepath, int bytes)
{
    int fd = open(filepath, O_RDONLY);
    char buff[bytes];
    int size;

    if (fd == -1)
        return;
    size = read(fd, buff, bytes);
    if (size <= 0)
        return;
    write(1, buff, size);
    return;
}
