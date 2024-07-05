/*
** EPITECH PROJECT, 2019
** BSQ_bootstrap
** File description:
** Open a file and return the file descriptor
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int fs_open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    if (fd != -1)
        write(1, "SUCCESS\n", 8);
    else
        write(1, "FAILURE\n", 8);
    return fd;
}
