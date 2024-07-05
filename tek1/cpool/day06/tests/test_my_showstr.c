/*
** EPITECH PROJECT, 2019
** test_my_showstr
** File description:
** Some desc
*/

#include <criterion/criterion.h>

int my_showstr(char const *str);

Test(my_showstr, test_this_function)
{
    int i = my_showstr("I like \n \b pandas");
    cr_assert_eq(0, 0);
}