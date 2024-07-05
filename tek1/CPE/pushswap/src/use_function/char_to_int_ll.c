/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** char_to_int_ll
*/

#include <stdlib.h>
#include <stdio.h>
#include "pushswap.h"

static int process_digits(int sign, char const *nbr_str)
{
    int result = 0;

    for (; *nbr_str && *nbr_str >= '0' && *nbr_str <= '9'; ++nbr_str)
        result = result * 10 + (*nbr_str - '0');
    return (result * sign);
}

static int char_to_int(char *nbr_str)
{
    int sign = 1;

    for (; *nbr_str && !(*nbr_str >= '0' && *nbr_str <= '9'); ++nbr_str)
        if (*nbr_str == '-')
            sign *= -1;
    return (process_digits(sign, nbr_str));
}

static t_link_t *create_node(char *nbr_str, t_link_t *previous)
{
    t_link_t *current = malloc(sizeof(t_link_t));

    if (current == NULL)
        return (NULL);
    current->value = char_to_int(nbr_str);
    current->next = previous;
    return (current);
}

t_link_t *char_to_int_ll(int argc, char **argv)
{
    t_link_t *previous = NULL;

    for (int i = argc - 1; i >= 1; --i) {
        previous = create_node(argv[i], previous);
        if (previous == NULL)
            return (NULL);
    }
    return (previous);
}