/*
** EPITECH PROJECT, 2019
** CPool_Day12_2019
** File description:
** Test the cat function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>

void cat(char const *file_path);

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(cat, show_1_file_data, .init=redirect_all_stdout)
{
    char const *argv = "./tests/test_file";

    cat(argv);
    cr_assert_stdout_eq_str("I like pastas\nBut I like lasagna more", "");
}

Test(cat, error_no_file, .init=redirect_all_stdout)
{
    char const *argv = "zbub";

    cat(argv);
    cr_assert_stdout_eq_str("cat: zbub: No such file or directory\n", "");
}