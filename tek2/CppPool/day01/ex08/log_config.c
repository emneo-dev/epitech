/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD01-alexandre.flion
** File description:
** log_config
*/

#include <stddef.h>
#include <unistd.h>

#include "log.h"

enum log_level get_set_log_level(int set, enum log_level level)
{
    static enum log_level lvl = ERROR;

    if (set)
        lvl = level;
    return (lvl);
}

enum log_level get_log_level(void)
{
    return get_set_log_level(0, ERROR);
}

enum log_level set_log_level(enum log_level level)
{
    return get_set_log_level(1, level);
}

int set_log_file(const char *file_name)
{
    return get_set_fd(1, file_name, 0);
}

int close_log_file(void)
{
    int fd = get_set_fd(0, NULL, 0);

    if (fd >= -1 && fd <= 2)
        return (0);
    if (close(fd))
        return (1);
    return (0);
}