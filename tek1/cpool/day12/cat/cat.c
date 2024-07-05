/*
** EPITECH PROJECT, 2019
** CPool_Day12_2019
** File description:
** Main file for the cat replica
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <my.h>
#include <unistd.h>

void cat(char const *file_path)
{
    int fd;
    char buffer[1024];
    int size = 1;

    fd = open(file_path, O_RDONLY);
    if (fd == -1) {
        my_putstr("cat: ");
        my_putstr(file_path);
        my_putstr(": No such file or directory\n");
        return;
    }
    size = read(fd, buffer, 1024);
    while (size != 0) {
        for (int i = 0; i < size; i++)
            my_putchar(buffer[i]);
        size = read(fd, buffer, 1024);
    }
    return;
}

void no_arg_cat(void)
{
    int fd;
    char buffer[1024];
    int size = 1;

    size = read(1, buffer, 1024);
    while (size != 0) {
        for (int i = 0; i < size; i++)
            my_putchar(buffer[i]);
        size = read(1, buffer, 1024);
    }
    return;
}