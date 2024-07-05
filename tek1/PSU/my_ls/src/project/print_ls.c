/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** print_ls
*/

#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my.h"
#include "ls.h"

static void handle_regular(args_t *args, char const *str)
{
    if (!args->l_t && !args->l_r && !args->u_r && !args->l_d && !args->l_l)
        my_putstrln(str);
}

static void handle_flag(DIR *current_dir, char const *str, args_t *args)
{
    if (args->l_l)
        l_flag(current_dir, str, args);
}

static void add_new_line(paths_t *path)
{
    if (path->next)
        write(1, "\n", 1);
}

// To fix the coding style here lign 43-51
int print_ls(args_t *args)
{
    paths_t *path = args->paths;
    DIR *current_dir = NULL;
    struct stat sb;

    for (; path; path = path->next) {
        current_dir = opendir(path->str);
        if (stat(path->str, &sb) == -1) {
            no_file(path->str);
            continue;
        }
        disp_entry(path->str, args);
        if (!S_ISDIR(sb.st_mode))
            handle_regular(args, path->str);
        else if (!args->l_t && !args->l_r && !args->l_d &&
            !args->l_l)
            no_print_args(current_dir, path->str);
        else
            handle_flag(current_dir, path->str, args);
        add_new_line(path);
    }
    return (0);
}