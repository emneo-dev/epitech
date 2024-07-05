/*
** EPITECH PROJECT, 2019
** BSQ_bootstrap
** File description:
** Understand the value of the previous return
*/

#include <unistd.h>

static void print_success_read(int ret, int size)
{
    if (ret == size)
        write(1, "read completed the entire buffer\n", 33);
    else
        write(1, "read didn't complete the entire buffer\n", 39);
    return;
}

void fs_understand_return_of_read(int fd, char *buffer, int size)
{
    int ret = read(fd, buffer, size);
    if (ret == -1)
        write(1, "read failed\n", 12);
    else if (!ret)
        write(1, "read has nothing more to read\n", 30);
    else
        print_success_read(ret, size);
    return;
}
