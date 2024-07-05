/*
** EPITECH PROJECT, 2019
** test_my_strupcase
** File description:
** Test a function
*/

#include <criterion/criterion.h>

char *my_strupcase(char *str);

Test(my_strupcase, put_a_string_in_uppercase)
{
    char str[12] = "HeLlO wOrLd";
    my_strupcase(str);
    cr_assert_str_eq(str, "HELLO WORLD");
}
