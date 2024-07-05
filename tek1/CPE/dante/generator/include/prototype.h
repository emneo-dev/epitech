/*
** EPITECH PROJECT, 2020
** generator
** File description:
** prototype
*/

#ifndef PROTOTYPE_H_
#define PROTOTYPE_H_

// CHECK
int check_argument(int ac, char **av, generator_t *generator_o);
int check_argument_perfect(char **av, generator_t *generator_o);
int check_argument_imperfect(char **av, generator_t *generator_o);

// INIT
int init(generator_t *generator_o);
int init_malloc_map(generator_t *generator_o);
int init_map(generator_t *generator_o);

// SETUP
int setup(generator_t *generator_o);
int setup_algo(generator_t *generator_o);
int setup_broke_walls(generator_t *generator_o);

#endif /* !PROTOTYPE_H_ */