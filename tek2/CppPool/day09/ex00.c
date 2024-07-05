//
// Created by huntears on 1/14/21.
//

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#include "ex00.h"

static void koala_initializer(koala_t *this, char *_name, char is_A_Legend)
{
    this->m_parent.m_name = malloc(sizeof(char) * (strlen(_name) + 1));
    assert(this->m_parent.m_name != NULL);
    strcpy(this->m_parent.m_name, _name);
    this->m_is_a_legend = is_A_Legend;
    this->m_parent.m_power = is_A_Legend ? 42 : 0;
}

static void cthulhu_initializer(cthulhu_t *this)
{
    char name[] = "Cthulhu";

    this->m_name = malloc(sizeof(char) * (sizeof(name) + 1));
    this->m_power = 42;
    assert(this->m_name != NULL);
    strcpy(this->m_name, name);
}

cthulhu_t  *new_cthulhu()
{
    cthulhu_t *this = malloc(sizeof(cthulhu_t));

    assert(this != NULL);
    cthulhu_initializer(this);
    printf("----\nBuilding Cthulhu\n");
    return this;
}

koala_t *new_koala(char *name, char is_a_legend)
{
    koala_t *this = malloc(sizeof(koala_t));

    assert(this != NULL);
    koala_initializer(this, name, is_a_legend);
    printf("----\nBuilding Cthulhu\nBuilding %s\n", name);
    return this;
}

void print_power(cthulhu_t *this)
{
    printf("Power => %d\n", this->m_power);
}

void attack(cthulhu_t *this)
{
    if (this->m_power < 42) {
        printf("%s can't attack, he doesn't have enough power\n", this->m_name);
        return;
    }
    printf("%s attacks and destroys the city\n", this->m_name);
    this->m_power -= 42;
}

void sleeping(cthulhu_t *this)
{
    printf("Cthulhu sleeps\n");
    this->m_power += 42000;
}

void eat(koala_t *this)
{
    printf("%s eats\n", this->m_parent.m_name);
    this->m_parent.m_power += 42; // Really funny btw
}