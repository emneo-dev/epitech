/*
** EPITECH PROJECT, 2021
** nmobjdump
** File description:
** load_file_in_memory
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stddef.h>
#include <stdio.h>

#include "nm.h"

static int error_check(file_t *file, int fd, const char *filename,
    const char *call)
{
    if (S_ISDIR(file->s.st_mode)) {
        close(fd);
        fprintf(stderr, "%s: Warning: '%s' is a directory\n", call, filename);
        return -1;
    }
    if (!S_ISREG(file->s.st_mode)) {
        close(fd);
        fprintf(stderr, "%s: Warning: '%s' is not an ordinary file\n",
            call, filename);
        return -1;
    }
    if (file->s.st_size == 0) {
        close(fd);
        fprintf(stderr, "%s: %s: file format not recognized\n", call, filename);
        return -1;
    }
    return 0;
}

int load_file_in_memory(file_t *file, const char *filename, const char *call)
{
    int fd = 0;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "%s: '%s': No such file\n", call, filename);
        return -1;
    }
    fstat(fd, &(file->s));
    if (error_check(file, fd, filename, call))
        return -1;
    file->buffer = mmap(NULL, file->s.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (file->buffer == (void *)-1) {
        close(fd);
        return -1;
    }
    return 0;
}