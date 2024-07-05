/*
** EPITECH PROJECT, 2019
** test_my_strncpy
** File description:
** Test for my_strncpy
*/

#include <criterion/criterion.h>

char *my_strncpy(char *dest, char const *src, int n);

Test(my_strncpy, copy_five_characters_in_empty_array)
{
    char dest[6] = {0};

    strncpy(dest, "HelloWorld", 5);
    cr_assert_str_eq(dest, "Hello");
}

Test(my_strncpy, copy_string_in_empty_array)
{
    char my_dest[11] = "AAAAAAAAAA";
    char dest[11] = "AAAAAAAAAA";

    my_strncpy(my_dest, "Hello", 7);
    strncpy(dest, "Hello", 7);
    cr_assert_str_eq(my_dest, dest);
}