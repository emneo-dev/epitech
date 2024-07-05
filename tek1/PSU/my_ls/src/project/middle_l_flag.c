/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** middle_l_flag
*/

#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>
#include "my.h"
#include "ls.h"

void middle_l_flag(struct stat sb)
{
    my_put_nbr(sb.st_nlink);
    write(1, " ", 1);
    my_putstr(getpwuid(sb.st_uid)->pw_name);
    write(1, " ", 1);
    my_putstr(getgrgid(sb.st_gid)->gr_name);
    write(1, " ", 1);
    my_put_nbr(sb.st_size);
    write(1, " ", 1);
    write(1, ctime(&sb.st_mtime) + 4, my_strlen(ctime(&sb.st_mtime)) - 13);
    write(1, " ", 1);
}