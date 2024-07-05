/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Get the number at the beginning of the file
*/

#include <bsq.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

fnb_t get_number(int fd)
{
    char buff;
    read(fd, &buff, 1);
    fnb_t ret;
    ret.number = 0;
    for (ret.length = 0; buff != '\n'; read(fd, &buff, 1), ret.length++) {
        ret.number *= 10;
        ret.number += buff - 48;
    }
    return (ret);
}
