/*
** EPITECH PROJECT, 2019
** BSQ_bootstrap
** File description:
** Display the first line from a file descriptor
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void fs_print_first_line(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buff[500];
    int size;

    if (fd == -1)
        return;
    size = read(fd, buff, 500);
    if (size <= 0)
        return;
    for (int i = 0; *(buff + i) != '\n'; i++)
        write(1, buff + i, 1);
    return;
}
