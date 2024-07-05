/*
** EPITECH PROJECT, 2019
** test_my_strlowcase
** File description:
** Some dec
*/

#include <criterion/criterion.h>

char *my_strlowcase(char *str);

Test(my_test_my_strlowcase, put_string_into_lowercase)
{
    char str[12] = "HeLlO wOrLd";
    my_strlowcase(str);
    cr_assert_str_eq(str, "hello world");
}
