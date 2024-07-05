/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** smart_write
*/

#include <unistd.h>
#include <stddef.h>

void smart_write(int fd, const char *str, size_t size)
{
    size_t bytes_written = 0;

    bytes_written = write(fd, str, size);
    if (bytes_written < size)
        smart_write(fd, str + bytes_written, size - bytes_written);
}