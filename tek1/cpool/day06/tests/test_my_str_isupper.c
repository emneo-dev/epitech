/*
** EPITECH PROJECT, 2019
** test_my_str_isupper
** File description:
** Some desc
*/

#include <criterion/criterion.h>

int my_str_isupper(char const *str);

Test(my_str_isupper, check_a_upper_string)
{
    char str[11] = "HELLOWORLD";
    int i = my_str_isupper(str);
    cr_assert_eq(i, 1);
}

Test(my_str_isupper, check_a_non_upper_string)
{
    char str[11] = "HelloWorld";
    int i = my_str_isupper(str);
    cr_assert_eq(i, 0);
}