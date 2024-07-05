/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** r_flag
*/

#include <sys/stat.h>
#include <dirent.h>
#include "my.h"
#include "ls.h"

static void ur_flag_rec(args_t *args, DIR *current_dir, char const *str)
{
    struct dirent *file = NULL;

    if (!current_dir)
        return;
    while ((file = readdir(current_dir)) != NULL)
        if (file->d_name[0] != '.' && file->d_type == DT_DIR) {
            add_path(args, append_path(str, file->d_name));
            ur_flag_rec(args, opendir(append_path(str, file->d_name)),
            append_path(str, file->d_name));
        }
}

void ur_flag(args_t *args)
{
    paths_t *path = args->paths;
    struct stat sb;
    int max_rec = args->paths_len;

    for (int i = 0; i < max_rec; path = path->next, i++) {
        stat(path->str, &sb);
        if (S_ISDIR(sb.st_mode))
            ur_flag_rec(args, opendir(path->str), path->str);
    }
}