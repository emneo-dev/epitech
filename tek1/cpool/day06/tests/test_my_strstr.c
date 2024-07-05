/*
** EPITECH PROJECT, 2019
** test_my_strstr
** File description:
** Some desc
*/

#include <criterion/criterion.h>

char *my_strstr(char *str, char const *to_find);

Test(my_strstr, find_a_string_into_another_string)
{
    char s1[4] = "llo";
    char s2[3] = "lo";
    char s3[10] = "Hamcurger";
    char *ptr = my_strstr(s1, s2);

    printf("\n%p\n%p\n", ptr, s1 + 1);

    cr_assert_eq(ptr, s1 + 1);
    ptr = my_strstr(s3, s2);
    cr_assert_eq(ptr, 0);
}

Test(my_strstr, find_a_string_into_another_string_2)
{
    char s1[10] = "Hamcurger";
    char s2[7] = "burger";
    char *ptr = my_strstr(s1, s2);

    cr_assert_eq(ptr, 0);
}

Test(my_strstr, find_a_string_into_another_string_3)
{
    char s1[26] = "all the people are okay";
    char s2[17] = "all the people";
    char *ptr = my_strstr(s1, s2);

    cr_assert_eq(ptr, s1);
}
