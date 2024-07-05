/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** print_perms
*/

#include <sys/stat.h>
#include "my.h"

void print_perms(struct stat sb)
{
    my_putchar(S_ISDIR(sb.st_mode) ? 'd' : '-');
    my_putchar(sb.st_mode & S_IRUSR ? 'r' : '-');
    my_putchar(sb.st_mode & S_IWUSR ? 'w' : '-');
    my_putchar(sb.st_mode & S_IXUSR ? 'x' : '-');
    my_putchar(sb.st_mode & S_IRGRP ? 'r' : '-');
    my_putchar(sb.st_mode & S_IWGRP ? 'w' : '-');
    if ((sb.st_mode & S_ISGID) && !(sb.st_mode & S_IXGRP))
        my_putchar('S');
    else if ((sb.st_mode & S_ISGID) && (sb.st_mode & S_IXGRP))
        my_putchar('s');
    else
        my_putchar((sb.st_mode & S_IXGRP) ? ('x') : ('-'));
    my_putchar(sb.st_mode & S_IROTH ? 'r' : '-');
    my_putchar(sb.st_mode & S_IWOTH ? 'w' : '-');
    if ((sb.st_mode & S_ISVTX) && !(sb.st_mode & S_IXOTH))
        my_putstr("T ");
    else if ((sb.st_mode & S_ISVTX) && (sb.st_mode & S_IXOTH))
        my_putstr("t ");
    else
        my_putstr((sb.st_mode & S_IXOTH) ? ("x ") : ("- "));
}