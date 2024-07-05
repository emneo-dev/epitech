/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** Test the my_params_to_list function
*/

#include <criterion/criterion.h>
#include <mylist.h>
#include <my_rev_list.h>
#include <my_params_to_list.h>

Test(my_rev_list, reverse_the_node_of_a_linked_list)
{
    char * const av[3] = {"Jaime", "les", "pâtes"};

    struct linked_list *list = my_params_to_list(3, av);
    my_rev_list(&list);
    cr_assert(list->data == "Jaime");
}
