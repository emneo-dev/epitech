/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD03-alexandre.flion
** File description:
** join
*/

#include <string.h>
#include <stdint.h>

#include "string.h"

void join_c(string_t *this, char delim, const char * const * tab)
{
    const char separator[2] = { delim };

    this->assign_c(this, "");
    for (uint32_t i = 0; tab[i]; i++) {
        this->append_c(this, tab[i]);
        if (tab[i + 1])
            this->append_c(this, separator);
    }
}

void join_s(string_t *this, char delim, const string_t * const * tab)
{
    const char separator[2] = { delim };

    this->assign_c(this, "");
    for (uint32_t i = 0; tab[i]; i++) {
        this->append_c(this, tab[i]->str);
        if (tab[i + 1])
            this->append_c(this, separator);
    }
}