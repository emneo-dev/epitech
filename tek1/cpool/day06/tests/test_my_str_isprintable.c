/*
** EPITECH PROJECT, 2019
** test_my_str_isprintable
** File description:
** Some desc
*/

#include <criterion/criterion.h>

int my_str_isprintable(char const *str);

Test(my_str_isprintable, check_a_printable_string)
{
    char str[12] = "Hello World";
    int i = my_str_isprintable(str);
    cr_assert_eq(i, 1);
}

Test(my_str_isprintable, check_a_non_printable_string)
{
    char str[2] = {10, '\0'};
    int i = my_str_isprintable(str);
    cr_assert_eq(i, 0);
}