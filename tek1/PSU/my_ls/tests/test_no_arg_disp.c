/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** test_no_arg_disp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ls.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdin();
    cr_redirect_stdout();
}

Test(no_print_arg, include_folder, .timeout = 1, .init = redirect_all_stdout)
{
    args_t *parsed_args = NULL;
    DIR *current_dir = NULL;

    parsed_args = malloc(sizeof(args_t));
    cr_assert_neq(parsed_args, NULL);
    parsed_args->paths = malloc(sizeof(paths_t));
    cr_assert_neq(parsed_args->paths, NULL);
    parsed_args->paths->next = NULL;
    parsed_args->paths->str = "./tests/general_tests/to_show";
    parsed_args->l_d = 0;
    parsed_args->l_l = 0;
    parsed_args->l_r = 0;
    parsed_args->l_t = 0;
    parsed_args->paths_len = 1;
    current_dir = opendir(parsed_args->paths->str);
    cr_assert_neq(current_dir, NULL);
    no_print_args(current_dir, parsed_args->paths->str);
    //cr_expect_stdout_eq_str("1.txt\n3.txt\n2.txt\n");
}

Test(print_ls, wrong_folder, .timeout = 1, .init = redirect_all_stdout)
{
    args_t *parsed_args = NULL;

    parsed_args = malloc(sizeof(args_t));
    cr_assert_neq(parsed_args, NULL);
    parsed_args->paths = malloc(sizeof(paths_t));
    cr_assert_neq(parsed_args->paths, NULL);
    parsed_args->paths->next = NULL;
    parsed_args->paths->str = "issou";
    parsed_args->l_d = 0;
    parsed_args->l_l = 0;
    parsed_args->l_r = 0;
    parsed_args->l_t = 0;
    parsed_args->paths_len = 1;
    print_ls(parsed_args);
    cr_expect_stdout_eq_str("my_ls: cannot access 'issou': No such file or directory\n");
}

Test(no_print_arg, no_perm_folder, .timeout = 1, .init = redirect_all_stdout)
{
    args_t *parsed_args = NULL;
    DIR *current_dir = NULL;

    parsed_args = malloc(sizeof(args_t));
    cr_assert_neq(parsed_args, NULL);
    parsed_args->paths = malloc(sizeof(paths_t));
    cr_assert_neq(parsed_args->paths, NULL);
    parsed_args->paths->next = NULL;
    parsed_args->paths->str = "./tests/general_tests/no_perm";
    parsed_args->l_d = 0;
    parsed_args->l_l = 0;
    parsed_args->l_r = 0;
    parsed_args->l_t = 0;
    parsed_args->paths_len = 1;
    current_dir = opendir(parsed_args->paths->str);
    no_print_args(current_dir, parsed_args->paths->str);
    //cr_expect_stdout_eq_str("my_ls: cannot open directory './tests/general_tests/no_perm': Permission denied\n");
}