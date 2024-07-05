/*
** EPITECH PROJECT, 2020
** sample_project
** File description:
** test_sample
*/

#include <criterion/criterion.h>
#include "ls.h"

Test(parse_args, no_args, .timeout = 1)
{
    args_t *parsed_args = NULL;
    int ac = 1;
    char const *av[1] = {"./my_ls"};

    parsed_args = parse_args(ac, av);
    cr_assert_neq(parsed_args, NULL);
    cr_expect_eq(parsed_args->l_d, 0);
    cr_expect_eq(parsed_args->l_l, 0);
    cr_expect_eq(parsed_args->l_r, 0);
    cr_expect_eq(parsed_args->l_t, 0);
    cr_expect_eq(parsed_args->u_r, 0);
    cr_expect_eq(parsed_args->paths_len, 1);
    cr_expect_neq(parsed_args->paths, NULL);
    cr_expect_str_eq(parsed_args->paths->str, ".");
    cr_expect_eq(parsed_args->paths->next, NULL);
}

Test(parse_args, only_flags, .timeout = 1)
{
    args_t *parsed_args = NULL;
    int ac = 3;
    char const *av[3] = {"./my_ls", "-llr", "-R"};

    parsed_args = parse_args(ac, av);
    cr_assert_neq(parsed_args, NULL);
    cr_expect_eq(parsed_args->l_d, 0);
    cr_expect_eq(parsed_args->l_l, 1);
    cr_expect_eq(parsed_args->l_r, 1);
    cr_expect_eq(parsed_args->l_t, 0);
    cr_expect_eq(parsed_args->u_r, 1);
    cr_expect_eq(parsed_args->paths_len, 1);
    cr_expect_neq(parsed_args->paths, NULL);
    cr_expect_str_eq(parsed_args->paths->str, ".");
    cr_expect_eq(parsed_args->paths->next, NULL);
}

Test(parse_args, two_paths, .timeout = 1)
{
    args_t *parsed_args = NULL;
    int ac = 3;
    char const *av[3] = {"./my_ls", "a", "bb"};

    parsed_args = parse_args(ac, av);
    cr_assert_neq(parsed_args, NULL);
    cr_expect_eq(parsed_args->l_d, 0);
    cr_expect_eq(parsed_args->l_l, 0);
    cr_expect_eq(parsed_args->l_r, 0);
    cr_expect_eq(parsed_args->l_t, 0);
    cr_expect_eq(parsed_args->u_r, 0);
    cr_expect_eq(parsed_args->paths_len, 2);
    cr_expect_neq(parsed_args->paths, NULL);
    cr_expect_str_eq(parsed_args->paths->str, "a");
    cr_expect_neq(parsed_args->paths->next, NULL);
    cr_expect_str_eq(parsed_args->paths->next->str, "bb");
    cr_expect_eq(parsed_args->paths->next->next, NULL);
}

Test(parse_args, mix_of_everything, .timeout = 1)
{
    args_t *parsed_args = NULL;
    int ac = 6;
    char const *av[6] = {"./my_ls", "a", "-llrd", "bb", "-", "-R"};

    parsed_args = parse_args(ac, av);
    cr_assert_neq(parsed_args, NULL);
    cr_expect_eq(parsed_args->l_d, 1);
    cr_expect_eq(parsed_args->l_l, 1);
    cr_expect_eq(parsed_args->l_r, 1);
    cr_expect_eq(parsed_args->l_t, 0);
    cr_expect_eq(parsed_args->u_r, 1);
    cr_expect_eq(parsed_args->paths_len, 3);
    cr_expect_neq(parsed_args->paths, NULL);
    cr_expect_str_eq(parsed_args->paths->str, "a");
    cr_expect_neq(parsed_args->paths->next, NULL);
    cr_expect_str_eq(parsed_args->paths->next->str, "bb");
    cr_expect_neq(parsed_args->paths->next->next, NULL);
    cr_expect_str_eq(parsed_args->paths->next->next->str, "-");
    cr_expect_eq(parsed_args->paths->next->next->next, NULL);
}