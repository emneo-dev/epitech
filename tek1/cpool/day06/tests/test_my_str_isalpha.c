/*
** EPITECH PROJECT, 2019
** test_my_str_isalpha
** File description:
** Some desc
*/

#include <criterion/criterion.h>

int my_str_isalpha(char const *str);

Test(my_str_isalpha, check_a_alpha_string)
{
    char str[6] = "jesuis";
    int i = my_str_isalpha(str);
    cr_assert_eq(i, 1);
}

Test(my_str_isalpha, check_a_non_alpha_string)
{
    char str[7] = "je suis";
    int i = my_str_isalpha(str);
    cr_assert_eq(i, 0);
}