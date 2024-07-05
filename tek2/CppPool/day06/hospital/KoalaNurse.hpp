/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD06-alexandre.flion
** File description:
** KoalaNurse
*/

#ifndef KOALANURSE_HPP_
#define KOALANURSE_HPP_

#include <iostream>

#include "SickKoala.hpp"

class KoalaNurse {
public:
    KoalaNurse(int ID);
    ~KoalaNurse();
    void giveDrug(std::string drug, SickKoala *koala);
    void timeCheck();
    std::string readReport(std::string fileName);
    void say(std::string input);
    int ID;
protected:
private:
    bool isWorking;
};

#endif /* !KOALANURSE_HPP_ */
