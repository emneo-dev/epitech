/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD01-alexandre.flion
** File description:
** ex05
*/

#ifndef EX05_H_
#define EX05_H_

typedef union fo {
    struct {
        short foo;
        union {
            short foo;
            short bar;
        } bar;
    } foo;
    int bar;
} foo_t;

#endif /* !EX05_H_ */
