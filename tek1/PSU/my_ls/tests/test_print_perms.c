/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** test_print_perms
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ls.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdin();
    cr_redirect_stdout();
}

Test(print_perms, regular_file, .timeout = 1, .init = redirect_all_stdout)
{
    struct stat sb;

    stat("./tests/general_tests/to_show/1.txt", &sb);
    print_perms(sb);
    cr_expect_stdout_eq_str("-rw-r--r-- ");
}

Test(print_perms, folder, .timeout = 1, .init = redirect_all_stdout)
{
    struct stat sb;

    stat("./tests/general_tests/to_show", &sb);
    print_perms(sb);
    cr_expect_stdout_eq_str("drwxr-xr-x ");
}

Test(print_perms, no_perm_folder, .timeout = 1, .init = redirect_all_stdout)
{
    struct stat sb;

    stat("./tests/general_tests/no_perm", &sb);
    print_perms(sb);
    cr_expect_stdout_eq_str("d--------- ");
}