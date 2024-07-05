/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019 [WSL: Debian]
** File description:
** sh
*/

#ifndef SH_H_
#define SH_H_

typedef struct result_s {
    int do_exit;
    unsigned char status;
} result_t;

typedef struct env_s {
    char *data;
    struct env_s *next;
} env_t;

int sh(char **ep);
void print_prompt(void);
result_t handle_input(char *cmd, env_t **ep);
int is_a_builtin(char *cmd);
int get_cmd_len(char *cmd);
result_t handle_builtin(char *cmd, env_t **ep);
result_t handle_cmd(char *cmd, env_t *ep);
result_t sh_cd(char *cmd, env_t **ep);
result_t sh_env(char *cmd, env_t **ep);
result_t sh_setenv(char *cmd, env_t **ep);
result_t sh_unsetenv(char *cmd, env_t **ep);
result_t sh_exit(char *cmd, env_t **ep);
env_t *env_cpy(char **envp);
void destroy_env(env_t *env);
int my_ll_len(env_t *env);
char **env_ll_to_array(env_t *ep);
result_t my_exec(char **cmd, char **envp);
result_t path_exec(char **cmd_arr, char **envp);
char *append_path(char *first, char *second);
char *my_split_cpy(char *dest, char const *src, char sep);
char **my_str_split(char *str, char sep);
char **get_splited_path(char **envp);
int handle_incoming_pipe(char **ep);
char *append(char *first, char *second);

#endif /* !SH_H_ */
