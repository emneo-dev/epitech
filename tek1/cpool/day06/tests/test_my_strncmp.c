/*
** EPITECH PROJECT, 2019
** test_my_strncmp
** File description:
** Some desc
*/

#include <criterion/criterion.h>

int my_strncmp(char const *s1, char const *s2, int n);

Test(my_strncmp, check_differences_between_two_matching_strings)
{
    char s1[13] = "Test Stringh";
    char s2[12] = "Test String";
    int i = my_strncmp(s1, s2, 11);
    cr_assert_eq(i, 0);
}

Test(my_strncmp, check_differences_between_two_non_matching_strings)
{
    char s1[12] = "Test String";
    char s2[13] = "test Stringc";
    int i = my_strncmp(s1, s2, 13);
    cr_assert_neq(i, 0);
}
