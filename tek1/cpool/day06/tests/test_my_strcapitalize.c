/*
** EPITECH PROJECT, 2019
** test_my_strcapitalize
** File description:
** Some desc.
*/

#include <criterion/criterion.h>

char *my_strcapitalize(char *str);

Test(my_strcapitalize, capitalize_a_string)
{
    char str[46] = "hey, how are you? 42WORds forty-two fifty+one";
    my_strcapitalize(str);
    cr_assert_str_eq(str, "Hey, How Are You? 42words Forty-Two Fifty+One");
}
