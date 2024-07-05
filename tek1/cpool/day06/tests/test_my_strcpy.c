/*
** EPITECH PROJECT, 2019
** test_my_strcpy
** File description:
** Test for my_strcpy
*/

#include <criterion/criterion.h>

char *my_strcpy(char *dest, char const *src);

Test(my_strcpy, copy_characters_in_empty_array)
{
    char dest[6] = {0};

    strcpy(dest, "HelloWorld");
    cr_assert_str_eq(dest, "HelloWorld");
}

Test(my_strcpy, copy_string_in_empty_array)
{
    char my_dest[11] = "AAAAAAAAAA";
    char dest[11] = "AAAAAAAAAA";

    my_strcpy(my_dest, "Hello");
    strcpy(dest, "Hello");
    cr_assert_str_eq(my_dest, dest);
}