/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD03-alexandre.flion
** File description:
** clear
*/

#include "string.h"

void clear(string_t *this)
{
    this->assign_c(this, "");
}