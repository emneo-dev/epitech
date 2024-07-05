/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD01-alexandre.flion
** File description:
** log
*/

#ifndef LOG_H_
#define LOG_H_

enum log_level {
    ERROR,
    WARNING,
    NOTICE,
    INFO,
    DEBUG
};

// log_config.c
enum log_level get_log_level(void);
enum log_level set_log_level(enum log_level level);
int set_log_file(const char *file_name);
int close_log_file(void);

// log.c
int log_to_stdout(void);
int log_to_stderr(void);
void log_msg(enum log_level level, const char *fmt, ...);
int get_set_fd(int set, const char *file_name, int new_fd);

#endif /* !LOG_H_ */
