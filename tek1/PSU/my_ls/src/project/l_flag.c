/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** l_flag
*/

#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include "my.h"
#include "ls.h"

static void disp_total(char const *str)
{
	struct stat sb;
	struct dirent *current_dir;
	int total = 0;
	DIR *dir = opendir(str);

	while ((current_dir = readdir(dir)))
		if ((lstat(append_path(str, current_dir->d_name), &sb)) == 0)
			(current_dir->d_name[0] != '.') ? total += sb.st_blocks : 0;
	closedir(dir);
	my_putstr("total ");
    my_put_nbr(total / 2);
    write(1, "\n", 1);
}

void l_flag(DIR *current_dir, char const *str, args_t *args)
{
    struct dirent *file = NULL;

    (void)args;
    if (!current_dir) {
        my_putstr("my_ls: cannot open directory '");
        my_putstr(str);
        my_putstr("': Permission denied\n");
        return;
    }
    disp_total(str);
    while ((file = readdir(current_dir)) != NULL)
        if (file->d_name[0] != '.')
            print_l_flag(file, append_path(str, file->d_name));
}