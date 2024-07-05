/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD06-alexandre.flion
** File description:
** KoalaNurseList
*/

#ifndef KoalaNurseLIST_HPP_
#define KoalaNurseLIST_HPP_

#include "KoalaNurse.hpp"

class KoalaNurseList {
public:
    KoalaNurseList(KoalaNurse *patient);
    ~KoalaNurseList();
    bool isEnd();
    void append(KoalaNurseList *node);
    KoalaNurse *getFromID(int ID);
    KoalaNurseList *remove(KoalaNurseList *node);
    KoalaNurseList *removeFromID(int ID);
    KoalaNurse *getContent();
    KoalaNurseList *getNext();
    void dump();
    KoalaNurseList *next;
    KoalaNurse *data;

protected:
private:
};

#endif /* !KoalaNurseLIST_HPP_ */
