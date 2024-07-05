/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** Test the my_params_to_list function
*/

#include <criterion/criterion.h>
#include <mylist.h>
#include <my_params_to_list.h>

Test(my_params_to_list, put_3_params_into_a_linked_list)
{
    char * const av[3] = {"Jaime", "les", "pâtes"};

    struct linked_list *list = my_params_to_list(3, av);
    cr_assert(list != 0);
    cr_assert(list->next != 0);
    cr_assert(list->next->next != 0);
    cr_assert(list->next->next->next == 0);
}
