/*
** EPITECH PROJECT, 2019
** test_my_strcpm
** File description:
** Some desc
*/

#include <criterion/criterion.h>

int my_strcmp(char const *s1, char const *s2);

Test(my_strcmp, compare_two_strings)
{
    char s1[12] = "Test String";
    char s2[12] = "Test String";
    int i = my_strcmp(s1, s2);
    cr_assert_eq(i, 0);
}

Test(my_strcmp, compare_two_differents_strings)
{
    char s1[12] = "Test String";
    char s2[13] = "Test Stringc";
    int i = my_strcmp(s1, s2);
    cr_assert_neq(i, 0);
}