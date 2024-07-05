/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** pushswap
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "pushswap.h"

static void free_t_link(t_link_t *list)
{
    t_link_t *tmp;

    while (list != NULL) {
        tmp = list->next;
        free(list);
        list = tmp;
    }
    return;
}

static int get_lowest(t_link_t *list)
{
    int lowest = __INT_MAX__;

    for (; list; list = list->next)
        lowest = (list->value < lowest) ? list->value : lowest;
    return (lowest);
}

static void main_loop(t_link_t **l_a, t_link_t **l_b)
{
    int lowest = get_lowest(*l_a);

    while (*l_a != NULL) {
        if ((*l_a)->value == lowest) {
            write(1, " pb", 3);
            pb(l_a, l_b);
            lowest = get_lowest(*l_a);
        }
        else {
            write(1, " ra", 3);
            ra(l_a);
        }
    }
    while (*l_b != NULL) {
        write(1, " pa", 3);
        pa(l_a, l_b);
    }
    return;
}

static void first_pass(t_link_t **l_a, t_link_t **l_b)
{
    int lowest = get_lowest(*l_a);

    if ((*l_a)->value == lowest) {
        write(1, "pb", 2);
        pb(l_a, l_b);
    }
    else {
        write(1, "ra", 2);
        ra(l_a);
    }
    return;
}

int pushswap(int argc, char **argv)
{
    if (argc < 2)
        return (84);
    if (argc == 2)
        return (0);
    t_link_t *l_a = char_to_int_ll(argc, argv);
    t_link_t *l_b = NULL;
    first_pass(&l_a, &l_b);
    main_loop(&l_a, &l_b);
    write(1, "\n", 1);
    free_t_link(l_a);
    return (0);
}