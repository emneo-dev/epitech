/*
** EPITECH PROJECT, 2021
** my_teams_rfc
** File description:
** prot_pck
*/

#ifndef PROT_PCK_H_
    #define PROT_PCK_H_

    #include <stdint.h>

    struct pck {
        uint8_t id;
        uint64_t payload_length;
    } __attribute__ ((__packed__));

#endif /* !PROT_PCK_H_ */
