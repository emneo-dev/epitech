/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** Test the my_params_to_list function
*/

#include <criterion/criterion.h>
#include <mylist.h>
#include <my_list_size.h>
#include <my_params_to_list.h>

Test(my_list_size, get_the_size_of_a_3_nodes_list)
{
    char * const av[3] = {"Jaime", "les", "pâtes"};

    struct linked_list *list = my_params_to_list(3, av);
    cr_assert(3 == my_list_size(list));
}

Test(my_list_size, get_the_size_of_a_null_list)
{
    char * const av[0] = {};

    struct linked_list *list = my_params_to_list(0, av);
    cr_assert(0 == my_list_size(list));
}
