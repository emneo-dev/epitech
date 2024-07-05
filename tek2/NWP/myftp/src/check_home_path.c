/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** check_home_path
*/

#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool check_home_path(const char *home_path)
{
    DIR *dir = opendir(home_path);

    if (dir) {
        closedir(dir);
        return true;
    }
    fprintf(stderr, "Could not access home directory at %s :\n"
        "%s\n", home_path, strerror(errno));
    return false;
}