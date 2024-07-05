/*
** EPITECH PROJECT, 2019
** test_my_revstr
** File description:
** Test for my_revstr function
*/

#include <criterion/criterion.h>

#include <string.h>

char *my_revstr(char const *str);

Test(my_revstr, reverse_a_string)
{
    char str[12] = "Hello World";
    my_revstr(str);
    cr_assert_str_eq(str, "dlroW olleH");
}
