/*
** EPITECH PROJECT, 2019
** test_my_str_isalpha
** File description:
** Some desc
*/

#include <criterion/criterion.h>

int my_str_isnum(char const *str);

Test(my_str_isnum, check_a_num_string)
{
    char str[6] = "42069";
    int i = my_str_isnum(str);
    cr_assert_eq(i, 1);
}

Test(my_str_isnum, check_a_non_num_string)
{
    char str[9] = "akf";
    int i = my_str_isnum(str);
    cr_assert_eq(i, 0);
}