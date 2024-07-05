/*
** EPITECH PROJECT, 2019
** BSQ_bootstrap
** File description:
** Display 500 bytes from a file descriptor
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void fs_cat_500_bytes(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buff[500];
    int size;

    if (fd == -1)
        return;
    size = read(fd, buff, 500);
    if (size <= 0)
        return;
    write(1, buff, size);
    return;
}
