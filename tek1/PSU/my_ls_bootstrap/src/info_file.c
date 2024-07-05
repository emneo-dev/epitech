/*
** EPITECH PROJECT, 2020
** PSU_my_ls_bootstrap_2019
** File description:
** info_file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/sysmacros.h>
#include "my.h"

static char *get_name(char *filepath)
{
    int i = 0;

    for (i = 0; filepath[i]; i++);
    i--;
    for (; filepath[i] != '/' && i; i+=-1);
    if (filepath[i] == '/')
        i++;
    return (filepath + i);
}

static int get_infos(char const *filepath, struct stat *infos)
{
    if (stat(filepath, infos) == 0)
        return (0);
    return (-1);
}

static char get_file_type(struct stat *infos)
{
    switch (infos->st_mode & __S_IFMT) {
        case __S_IFBLK:
            return ('b');
        case __S_IFCHR:
            return ('c');
        case __S_IFDIR:
            return ('d');
        case __S_IFREG:
            return ('f');
        case __S_IFIFO:
            return ('p');
        case __S_IFLNK:
            return ('l');
        case __S_IFSOCK:
            return ('s');
        default:
            return ('?');
    }
}

static void display_infos(struct stat *infos, char *filepath)
{
    if (get_file_type(infos) == 'd')
        my_printf("Name:  %s/\n", get_name(filepath));
    else
        my_printf("Name:  %s\n", get_name(filepath));
    my_printf("Type:  %c\n", get_file_type(infos));
    my_printf("Inode:  %i\n", (int) infos->st_ino);
    my_printf("Hard Link:  %i\n", (int) infos->st_nlink);
    my_printf("Size:  %i\n", (int) infos->st_size);
    my_printf("Allocated space:  %i\n", ((int) infos->st_blocks) *
                                        ((int) infos->st_blksize));
    if (get_file_type(infos) == 'b') {
        my_printf("Minor:  %i\n", major(infos->st_rdev));
        my_printf("Major:  %i\n", minor(infos->st_rdev));
    } else {
        my_printf("Minor:  N/A\n");
        my_printf("Major:  N/A\n");
    }
    my_printf("UID:  %i\n", (int) infos->st_uid);
    my_printf("GID:  %i\n", (int) infos->st_gid);
}

int info_file(char *filepath)
{
    struct stat infos;
    if (get_infos(filepath, &infos) == -1) {
        write(1, "File not found\n", 15);
        return (84);
    }
    display_infos(&infos, filepath);
    return (0);
}