/*
** EPITECH PROJECT, 2021
** list.h
** File description:
** list
*/

#ifndef LIST_H_
#define LIST_H_

#include "container.h"

typedef struct NodeClass_s NodeClass;
typedef struct ListClass_s ListClass;

extern const Class *List;

typedef void (*node_set_link)(NodeClass *, NodeClass *);
typedef void (*node_set_value)(NodeClass *, NodeClass *);
typedef NodeClass *(*node_get_link)(NodeClass *);
typedef Object *(*node_get_value)(NodeClass *);

typedef void (*list_front_push)(ListClass *, ...);
typedef void (*list_back_push)(ListClass *, ...);
typedef void (*list_front_pop)(ListClass *);
typedef void (*list_back_pop)(ListClass *);
typedef NodeClass *(*list_get_value)(ListClass *, unsigned int);

typedef struct ListClass_s
{
    Container base;
    size_t _size;
    NodeClass *_first;
    NodeClass *_last;

    list_front_push __push_front__;
    list_back_push __push_back__;
    list_front_pop __pop_front__;
    list_back_pop __pop_back__;
    list_get_value __get_at__;
} ListClass;
#endif /* !LIST_H_ */