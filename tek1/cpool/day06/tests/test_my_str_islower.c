/*
** EPITECH PROJECT, 2019
** test_my_str_islower
** File description:
** Some desc
*/

#include <criterion/criterion.h>

int my_str_islower(char const *str);

Test(my_str_islower, check_a_lower_string)
{
    char str[10] = "helloworld";
    int i = my_str_islower(str);
    cr_assert_eq(i, 1);
}

Test(my_str_islower, check_a_non_lower_string)
{
    char str[10] = "HelloWorld";
    int i = my_str_islower(str);
    cr_assert_eq(i, 0);
}