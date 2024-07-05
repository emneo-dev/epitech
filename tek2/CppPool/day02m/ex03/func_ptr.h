/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD02M-alexandre.flion
** File description:
** func_ptr
*/

#ifndef FUNC_PTR_H_
#define FUNC_PTR_H_

#include "func_ptr_enum.h"

void print_normal(const char *str);
void print_reverse(const char *str);
void print_upper(const char *str);
void print_42(const char *str);
void do_action(action_t action, const char *str);

#endif /* !FUNC_PTR_H_ */
