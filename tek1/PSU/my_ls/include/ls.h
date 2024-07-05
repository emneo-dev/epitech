/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** ls
*/

#ifndef LS_H_
#define LS_H_

#ifndef NULL
#define NULL ((void *)0)
#endif /* !NULL */

#include <dirent.h>
#include <sys/stat.h>

typedef struct paths_s {
    char *str;
    struct paths_s *next;
} paths_t;

typedef struct args_s {
    int l_l;
    int u_r;
    int l_d;
    int l_r;
    int l_t;
    int paths_len;
    struct paths_s *paths;
} args_t;

int helper(void);
int my_ls(int argc, char const **argv);
args_t *parse_args(int argc, char const **argv);
int add_flag(args_t *parsed_args, char const *new_flag);
int print_ls(args_t *args);
void no_print_args(DIR *current_dir, char const *str);
void print_perms(struct stat sb);
int my_putstrln(char const *str);
char *append_path(char const *first, char const *second);
void print_l_flag(struct dirent *file, char const *str);
void l_flag(DIR *current_dir, char const *str, args_t *args);
void middle_l_flag(struct stat sb);
int add_path(args_t *parsed_args, char const *new_path);
void no_file(char const *str);
void disp_entry(char const *str, args_t *args);
void ur_flag(args_t *args);

#endif /* !LS_H_ */
