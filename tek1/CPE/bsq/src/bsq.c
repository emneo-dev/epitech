/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Entry point for the BSQ project
*/

#include <bsq.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const **argv)
{
    if (argc != 2)
        return (84);
    int fd = open(argv[1], O_RDONLY);
    if (fd < 3)
        return (84);
    close(fd);
    map_t current = load_file_to_mem(argv[1]);
    loop_value(&current);
    long int highest = get_highest(current);
    display_bsq(&current, argv[1], highest);
    return (0);
}
