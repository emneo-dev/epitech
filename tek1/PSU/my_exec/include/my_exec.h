/*
** EPITECH PROJECT, 2020
** PSU_my_exec_2019 [WSL: Debian]
** File description:
** my_exec
*/

#ifndef MY_EXEC_H_
#define MY_EXEC_H_

int my_exec(int argc, char **argv, char **envp);
char **str_to_word_array(char *str);
int my_putstr(char *str);
int my_strlen(char *str);
int my_strcpy(char *dest, char const *src);
int my_strcpy_arr(char *dest, char const *src);
void my_put_nbr(int nb);
int my_putchar(char c);

#endif /* !MY_EXEC_H_ */
