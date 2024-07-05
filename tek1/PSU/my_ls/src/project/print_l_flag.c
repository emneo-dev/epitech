/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** print_l_flag
*/

#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "my.h"
#include "ls.h"

void print_l_flag(struct dirent *file, char const *str)
{
    struct stat sb;
    char buff_lnk[1024];
    size_t size_lnk = 0;

    stat(str, &sb);
    print_perms(sb);
    middle_l_flag(sb);
    my_putstr(file->d_name);
    if (file->d_type == DT_LNK) {
        size_lnk = readlink(file->d_name, buff_lnk, 1024);
        my_putstr(" -> ");
        write(1, buff_lnk, size_lnk);
    }
    write(1, "\n", 1);
}