/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Header file containing all prototypes
*/

#ifndef SAMPLE_H_
#define SAMPLE_H_

int tetris(int argc, char **argv);
args_t *init_args(void);
args_t *arg_parsing(int argc, char **argv, args_t *args);
int game(args_t *args, tetr_t *tetr);
int debug(args_t *args, tetr_t *tetr);
void helper(void);
tetr_t *tetr_parsing(void);
tetr_t *setup_while(int i, DIR *current_dir, FILE *ofile);
void change_carriage(char *str);
int free_struct(args_t *args, tetr_t *tetr);
char *append(char const *first, char const *second);

#endif /* !SAMPLE_H_ */
