/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** Header file for the my_params_to_list function
*/

#ifndef MY_PARAMS_TO_LIST_H
#define MY_PARAMS_TO_LIST_H

static int my_put_in_list(struct linked_list **list, void *data);
linked_list_t *my_params_to_list(int ac, char * const *av);

#endif /* MY_PARAMS_TO_LIST_H */
