/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD06-alexandre.flion
** File description:
** SickKoalaList
*/

#ifndef SICKKOALALIST_HPP_
#define SICKKOALALIST_HPP_

#include "SickKoala.hpp"

class SickKoalaList {
public:
    SickKoalaList(SickKoala *patient);
    ~SickKoalaList();
    bool isEnd();
    void append(SickKoalaList *node);
    SickKoala *getFromName(std::string name);
    SickKoalaList *remove(SickKoalaList *node);
    SickKoalaList *removeFromName(std::string name);
    SickKoala *getContent();
    SickKoalaList *getNext();
    void dump();
    SickKoalaList *next;
    SickKoala *data;

protected:
private:
};

#endif /* !SICKKOALALIST_HPP_ */
