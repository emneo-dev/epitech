/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** ftp
*/

#ifndef FTP_H_
    #define FTP_H_

    #include <stdint.h>
    #include <arpa/inet.h>
    #include <stdbool.h>
    #include <sys/socket.h>
    #include <linux/limits.h>

    typedef enum connection_status_e {
        NOT_CONNECTED,
        USER_CONNECTED,
        CONNECTED
    } connection_status_t;

    typedef enum ftp_error_e {
        NO_ERROR,
        SOCK_CREATION_ERROR,
        BIND_ERROR,
        HOME_PATH_ERROR
    } ftp_error_t;

    typedef struct client_s {
        int sockfd;
        char current_path[PATH_MAX];
        struct sockaddr_in addr;
        bool is_used;
        char *read_buffer;
        size_t buffer_size;
        connection_status_t conn_status;
        char *username;
    } client_t;

    typedef struct server_s {
        uint16_t port;
        const char *home_path;
        int sockfd;
        struct sockaddr_in addr;
        ftp_error_t err;
        fd_set *my_set;
    } server_t;

    typedef int (* cmd_function_t)(char **, server_t *, client_t *);

    typedef struct cmd_suffix_s {
        char *suffix;
        cmd_function_t fun_ptr;
    } cmd_suffix_t;

    // See note attached to its implementation in launch_server_loop.c
    extern const size_t MAX_CLIENTS;

    void print_help(const char *executable_name);
    int launch_server(uint16_t port, const char *home_path);
    server_t create_server(uint16_t port, const char *home_path);
    void bind_server_socket(server_t *srv);
    bool check_home_path(const char *home_path);
    void destroy_client(client_t *client);
    int accept_client(client_t clients[MAX_CLIENTS], int srv_sock,
        const char *home_path);
    char *get_client_string(const client_t *client);
    int exec_raw_cmd(char *cmd, server_t *srv, client_t *client);
    void smart_write(int fd, const char *str, size_t size);
    int launch_server_loop(server_t *srv);
    void handle_fd_input(server_t *srv, client_t clients[MAX_CLIENTS],
        fd_set *my_set, int fd);
    int get_client_index(int fd, const client_t clients[MAX_CLIENTS]);
    int read_client(client_t *client, server_t *srv);

    // CMDs
    int exec_cmd_cduo(char **cmd, server_t *srv, client_t *client);
    int exec_cmd_cwd(char **cmd, server_t *srv, client_t *client);
    int exec_cmd_dele(char **cmd, server_t *srv, client_t *client);
    int exec_cmd_help(char **cmd, server_t *srv, client_t *client);
    int exec_cmd_list(char **cmd, server_t *srv, client_t *client);
    int exec_cmd_noop(char **cmd, server_t *srv, client_t *client);
    int exec_cmd_pass(char **cmd, server_t *srv, client_t *client);
    int exec_cmd_pasv(char **cmd, server_t *srv, client_t *client);
    int exec_cmd_port(char **cmd, server_t *srv, client_t *client);
    int exec_cmd_pwd(char **cmd, server_t *srv, client_t *client);
    int exec_cmd_quit(char **cmd, server_t *srv, client_t *client);
    int exec_cmd_retr(char **cmd, server_t *srv, client_t *client);
    int exec_cmd_stor(char **cmd, server_t *srv, client_t *client);
    int exec_cmd_user(char **cmd, server_t *srv, client_t *client);
    int exec_cmd_unknown(char **cmd, server_t *srv, client_t *client);

    int send_not_connected(const client_t *client);

    #define UNUSED(x) (void)(x)

#endif /* !FTP_H_ */
