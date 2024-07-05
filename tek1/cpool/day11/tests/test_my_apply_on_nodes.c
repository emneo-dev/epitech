/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** Test the my_params_to_list function
*/

#include <criterion/criterion.h>
#include <mylist.h>
#include <my_apply_on_nodes.h>
#include <my_params_to_list.h>
#include <my.h>

Test(my_apply_on_nodes, get_the_size_of_a_3_nodes_list)
{
    char * const av[3] = {"Jaime", "les", "pâtes"};

    struct linked_list *list = my_params_to_list(3, av);
    int (*ptr)(char*) = my_revstr;
    cr_assert_str_eq("pâtes", list->data);
}
