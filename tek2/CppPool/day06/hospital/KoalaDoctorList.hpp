/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD06-alexandre.flion
** File description:
** KoalaDoctorList
*/

#ifndef KoalaDoctorLIST_HPP_
#define KoalaDoctorLIST_HPP_

#include "KoalaDoctor.hpp"

class KoalaDoctorList {
public:
    KoalaDoctorList(KoalaDoctor *patient);
    ~KoalaDoctorList();
    bool isEnd();
    void append(KoalaDoctorList *node);
    KoalaDoctor *getFromName(std::string name);
    KoalaDoctorList *remove(KoalaDoctorList *node);
    KoalaDoctorList *removeFromName(std::string name);
    KoalaDoctor *getContent();
    KoalaDoctorList *getNext();
    void dump();
    KoalaDoctorList *next;
    KoalaDoctor *data;

protected:
private:
};

#endif /* !KoalaDoctorLIST_HPP_ */
