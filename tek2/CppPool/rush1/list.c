/*
** EPITECH PROJECT, 2019
** cpp_rush1
** File description:
** Exercice 06
*/

#include <stdlib.h>
#include <stdarg.h>
#include "raise.h"
#include "list.h"
#include "new.h"
#include "int.h"

typedef struct NodeClass_s
{
    Class class;
    Class *_type;
    Object *_value;
    NodeClass *_next;
    NodeClass *_prev;

    node_set_link __set_prev__;
    node_set_link __set_next__;
    node_set_value __set_value__;
    node_get_link __get_prev__;
    node_get_link __get_next__;
    node_get_value __get_value__;
} NodeClass;

typedef struct
{
    Iterator base;
    ListClass *_list;
    NodeClass *_current;
    size_t _idx;
} ListIteratorClass;

// ============== ITER ==============

static void ListIterator_ctor(ListIteratorClass *this, va_list *args)
{
    if (!this || !args)
        raise("NULL value given");
    this->_list = va_arg(*args, ListClass *);
    this->_idx = va_arg(*args, int);
    this->_current = this->_list->_first;
}

static bool ListIterator_eq(ListIteratorClass *this, ListIteratorClass *other)
{
    if (!this || !other)
        raise("NULL value given");
    return (this->_idx == other->_idx);
}

static bool ListIterator_gt(ListIteratorClass *this, ListIteratorClass *other)
{
    if (!this || !other)
        raise("NULL value given");
    return (this->_idx > other->_idx);
}

static bool ListIterator_lt(ListIteratorClass *this, ListIteratorClass *other)
{
    if (!this || !other)
        raise("NULL value given");
    return (this->_idx < other->_idx);
}

static void ListIterator_incr(ListIteratorClass *this)
{
    if (!this)
        raise("NULL value given");
    this->_current = this->_current->_next;
    this->_idx += 1;
}

static Object *ListIterator_getval(ListIteratorClass *this)
{
    if (!this)
        raise("NULL value given");
    if (this->_idx >= this->_list->_size)
        raise("Out of range");
    return (this->_current);
}

static void ListIterator_setval(ListIteratorClass *this, ...)
{
    va_list va;
    Object *new_obj = NULL;
    NodeClass *node = NULL;

    if (!this)
        raise("NULL value given");
    va_start(va, this);
    node = this->_current;
    node->_type = (Class *)va_arg(va, size_t);
    new_obj = va_new(node->_type, &va);
    delete(node->_value);
    node->_value = new_obj;
    va_end(va);
}

static const ListIteratorClass ListIteratorDescr = {
    {
        {
            .__size__ = sizeof(ListIteratorClass),
            .__name__ = "ListIterator",
            .__ctor__ = (ctor_t)&ListIterator_ctor,
            .__dtor__ = NULL,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = (binary_comparator_t)&ListIterator_eq,
            .__gt__ = (binary_comparator_t)&ListIterator_gt,
            .__lt__ = (binary_comparator_t)&ListIterator_lt,
        },
        .__incr__ = (incr_t)&ListIterator_incr,
        .__getval__ = (getval_t)&ListIterator_getval,
        .__setval__ = (setval_t)&ListIterator_setval,
    },
    ._list = NULL,
    ._idx = 0};

static const Class *ListIterator = (const Class *)&ListIteratorDescr;

// ============== Nodes ==============

static void Node_ctor(NodeClass *this, va_list *args) // TYPE VALUE
{
    if (!this || !args)
        raise("NULL value given");
    this->_type = va_arg(*args, Class *);
    if (!this->_type)
        raise("NULL value given");
    this->_value = va_new(this->_type, args);
}

static void Node_dtor(NodeClass *this)
{
    if (!this)
        raise("NULL value given");
    delete(this->_value);
}

static char *Node_str(NodeClass *this)
{
    if (!this)
        raise("Null value given");
    return str(this->_value);
}

static void Node_set_prev(NodeClass *this, NodeClass *other)
{
    if (!this || !other)
        raise("NULL value given");
    this->_prev = other;
}

static void Node_set_next(NodeClass *this, NodeClass *other)
{
    if (!this || !other)
        raise("NULL value given");
    this->_next = other;
}

static void Node_set_value(NodeClass *this, Class *type, ...)
{
    va_list va;
    Object *new_obj = NULL;

    if (!this || !type)
        raise("NULL value given");
    va_start(va, type);
    this->_type = type;
    new_obj = va_new(this->_type, &va);
    delete(this->_value);
    this->_value = new_obj;
    va_end(va);
}

static NodeClass *Node_get_prev(NodeClass *this)
{
    if (!this)
        raise("NULL value given");
    return this->_prev;
}

static NodeClass *Node_get_next(NodeClass *this)
{
    if (!this)
        raise("NULL value given");
    return this->_next;
}

static Object *Node_get_value(NodeClass *this)
{
    if (!this)
        raise("NULL value given");
    return this->_value;
}

static const NodeClass NodeDescr = {
    {
        .__size__ = sizeof(NodeClass),
        .__name__ = "Node",
        .__ctor__ = (ctor_t)&Node_ctor,
        .__dtor__ = (dtor_t)&Node_dtor,
        .__str__ = (to_string_t)&Node_str,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    ._type = NULL,
    ._value = NULL,
    ._next = NULL,
    ._prev = NULL,
    .__set_prev__ = (node_set_link)&Node_set_prev,
    .__set_next__ = (node_set_link)&Node_set_next,
    .__set_value__ = (node_set_value)&Node_set_value,
    .__get_prev__ = (node_get_link)&Node_get_prev,
    .__get_next__ = (node_get_link)&Node_get_next,
    .__get_value__ = (node_get_value)&Node_get_value
};

static const Class *Node = (const Class *)&NodeDescr;

// ============== LIST ==============

static void list_push_front(ListClass *this, ...)
{
    NodeClass *new_node = NULL;
    va_list va;

    va_start(va, this);
    if (!this)
        raise("Out of Memory");
    new_node = va_new(Node, &va);
    va_end(va);
    new_node->_next = this->_first;
    this->_first = new_node;
    if (!this->_size)
        this->_last = new_node;
    else {
        this->_first->_prev = NULL;
        this->_first->_next->_prev = this->_first;
    }
    (this->_size)++;
}

static void list_push_back(ListClass *this, ...)
{
    NodeClass *new_node = NULL;
    va_list va;

    va_start(va, this);
    if (!this)
        raise("Out of Memory");
    new_node = va_new(Node, &va);
    va_end(va);
    new_node->_prev = this->_last;
    this->_last = new_node;
    if (!this->_size)
        this->_first = new_node;
    else {
        this->_last->_next = NULL;
        this->_last->_prev->_next = this->_last;
    }
    (this->_size)++;
}

static void list_pop_front(ListClass *this)
{
    NodeClass *old_node = NULL;

    if (!this)
        raise("Out of Memory");
    old_node = this->_first;
    if (this->_first == this->_last) {
        this->_last = NULL;
    }
    this->_first = old_node->_next;
    delete(old_node);
    if (this->_first)
        this->_first->_prev = NULL;
    this->_size--;
}

static void list_pop_back(ListClass *this)
{
    NodeClass *old_node = NULL;

    if (!this)
        raise("Out of Memory");
    old_node = this->_last;
    if (this->_first == this->_last) {
        this->_first = NULL;
    }
    this->_last = old_node->_prev;
    delete(old_node);
    if (this->_last) {
        this->_last->_next = NULL;
    }
    this->_size--;
}

static NodeClass *List_get_at(ListClass *this, unsigned int position)
{
    NodeClass *node = NULL;

    if (!this)
        raise("Out of Memory");
    node = this->_first;
    for (unsigned int i = 0; i < position; i++) {
        if (!node)
            raise("Out of bounds");
        node = node->_next;
    }
    return (node);
}

static void List_ctor(ListClass *this, va_list *args) // SIZE TYPE VALUE
{
    if (!this || !args)
        raise("NULL value given");
}

static void List_dtor(ListClass *this)
{
    NodeClass *prev = NULL;
    NodeClass *next = NULL;

    if (!this)
        raise("NULL value given");
    prev = this->_first;
    while (prev) {
            next = prev->_next;
            delete(prev);
            prev = next;
    }
}

static size_t List_len(ListClass *this)
{
    if (!this)
        raise("NULL value given");
    return (this->_size);
}

static Iterator *List_begin(ListClass *this)
{
    if (!this)
        raise("NULL value given");
    return (new (ListIterator, this, 0));
}

static Iterator *List_end(ListClass *this)
{
    if (!this)
        raise("NULL value given");
    return (new (ListIterator, this, this->_size));
}

static Object *List_getitem(ListClass *this, ...)
{
    va_list va;
    NodeClass *node = NULL;
    size_t index = 0;

    if (!this)
        raise("NULL value given");
    va_start(va, this);
    index = va_arg(va, size_t);
    if (index < this->_size) {
        node = List_get_at(this, index);
        return (node->_value);
    }
    va_end(va);
    return (NULL);
}

static void List_setitem(ListClass *this, ...)
{
    size_t pos = 0;
    va_list va;
    Object *new_obj = NULL;
    NodeClass *node = NULL;

    if (!this)
        raise("NULL value given");
    va_start(va, this);
    pos = va_arg(va, size_t);
    if (pos >= this->_size)
        raise("Index out of bounds");
    node = List_get_at(this, pos);
    new_obj = va_new(node->_type, &va);
    delete(node->_value);
    node->_value = new_obj;
    va_end(va);
}

static char *List_str(ListClass *this)
{
    int len = 0;
    NodeClass *node =  NULL;
    char *str = NULL;
    Class *obj_class = NULL;
    char *res = NULL;

    if (!this)
        raise("NULL value given");

    // calculate str size
    len += snprintf(NULL, 0, "<List ()>");
    node = this->_first;
    while (node) {
        if (!node->_value)
            continue;
        obj_class = (Class *)node->_value;
        if (obj_class->__str__) {
            str = obj_class->__str__(obj_class);
            if (!str)
                raise("Out of memory");
            len += strlen(str) + 2;
            free(str);
        }
        else {
            len += snprintf(NULL, 0, "<%s>, ", obj_class->__name__);
        }
        if (!node->_next)
                len -= 2;
        node = node->_next;
    }

    // malloc str
    res = malloc(sizeof(char) * (len + 1));
    if (!res)
        raise("Out of Memory");

    // get string
    len = sprintf(res, "<List (");
    node = this->_first;
    while (node) {
        if (!node->_value)
            continue;
        obj_class = (Class *)node->_value;
        if (obj_class->__str__) {
            str = obj_class->__str__(obj_class);
            if (node->_next)
                len += sprintf(&(res[len]), "%s, ", str);
            else
                len += sprintf(&(res[len]), "%s", str);
            free(str);
        }
        else {
            if (node->_next)
                len += sprintf(&(res[len]), "<%s>, ", obj_class->__name__);
            else
                len += sprintf(&(res[len]), "<%s>", obj_class->__name__);
        }
        node = node->_next;
    }
    len += sprintf(&(res[len]), ")>");
    res[len] = '\0';
    return res;
}

static const ListClass _descr = {
    {
        {
            .__size__ = sizeof(ListClass),
            .__name__ = "List",
            .__ctor__ = (ctor_t)&List_ctor,
            .__dtor__ = (dtor_t)&List_dtor,
            .__str__ = (to_string_t)&List_str,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__len__ = (len_t)&List_len,
        .__begin__ = (iter_t)&List_begin,
        .__end__ = (iter_t)&List_end,
        .__getitem__ = (getitem_t)&List_getitem,
        .__setitem__ = (setitem_t)&List_setitem,
    },
    ._size = 0,
    ._first = NULL,
    ._last = NULL,
    .__push_front__ = (list_front_push)&list_push_front,
    .__push_back__ = (list_back_push)&list_push_back,
    .__pop_front__ = (list_front_pop)&list_pop_front,
    .__pop_back__ = (list_back_pop)&list_pop_back,
    .__get_at__ = (list_get_value)&List_get_at
};

const Class *List = (const Class *)&_descr;
