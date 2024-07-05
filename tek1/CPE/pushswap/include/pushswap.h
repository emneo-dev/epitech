/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** pushswap
*/

#ifndef PUSHSWAP_H_
#define PUSHSWAP_H_

typedef struct t_link_s {
    int value;
    struct t_link_s *next;
} t_link_t;

int pushswap(int argc, char **argv);
t_link_t *char_to_int_ll(int argc, char **argv);
void push_a_to_b(t_link_t **a, t_link_t **b);
void swap_values(int *a, int *b);
void sa(t_link_t *list);
void pa(t_link_t **a, t_link_t **b);
void pb(t_link_t **a, t_link_t **b);
void ra(t_link_t **list);
int is_sorted(t_link_t *list);

#endif /* !PUSHSWAP_H_ */