/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD01-alexandre.flion
** File description:
** log
*/

#include <fcntl.h>
#include <stddef.h>
#include <time.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

#include "log.h"

// 0 to get
// 1 to open file (Returns 1 if failed)
// 2 to set fd
int get_set_fd(int set, const char *file_name, int new_fd)
{
    static int fd = -1;

    if (!set)
        return (fd);
    close_log_file();
    if (set == 2)
        fd = new_fd;
    else if ((fd = open(file_name, O_CREAT | O_APPEND | O_WRONLY, 0644)) == -1)
        return (1);
    return (0);
}

int log_to_stdout(void)
{
    return (get_set_fd(2, NULL, 1));
}

int log_to_stderr(void)
{
    return (get_set_fd(2, NULL, 2));
}

static void print_header(enum log_level level, int fd)
{
    time_t cur_time = time(NULL);
    char *datetime = ctime(&cur_time);

    datetime[strlen(datetime) - 1] = '\0';
    switch(level)
    {
        case ERROR:
            dprintf(fd, "%s [ERROR]: ", datetime);
            return;
        case WARNING:
            dprintf(fd, "%s [WARNING]: ", datetime);
            return;
        case NOTICE:
            dprintf(fd, "%s [NOTICE]: ", datetime);
            return;
        case INFO:
            dprintf(fd, "%s [INFO]: ", datetime);
            return;
        case DEBUG:
            dprintf(fd, "%s [DEBUG]: ", datetime);
    }
}

void log_msg(enum log_level level, const char *fmt, ...)
{
    va_list vl;
    int fd = get_set_fd(0, NULL, 0);

    va_start(vl, fmt);
    if (level > get_log_level())
        return;
    print_header(level, fd);
    vdprintf(fd, fmt, vl);
    va_end(vl);
}