/*
** EPITECH PROJECT, 2021
** my_teams_rfc
** File description:
** prot_error
*/

#ifndef PROT_ERROR_H_
    #define PROT_ERROR_H_

    enum pck_error_codes {
        ERR_INTERNAL = 0,
        ERR_NOT_FOUND = 1,
        ERR_NO_PERM = 2,
        ERR_EMPTY_FIELD = 3
    } __attribute__ ((__packed__));

#endif /* !PROT_ERROR_H_ */
