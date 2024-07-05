/*
** EPITECH PROJECT, 2019
** BSQ_bootstrap
** File description:
** Return the positive integer written in the first line
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int fs_get_number_from_first_line(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buff[500];
    int size;
    int ret = 0;

    if (fd == -1)
        return (-1);
    size = read(fd, buff, 500);
    if (size <= 0)
        return (-1);
    for (int i = 0; *(buff + i) != '\n'; i++) {
        char current = *(buff + i);
        if (current <= '9' && current >= '0') {
            ret *= 10;
            ret += current - '0';
        } else
            return (-1);
    }
    return (ret);
}
