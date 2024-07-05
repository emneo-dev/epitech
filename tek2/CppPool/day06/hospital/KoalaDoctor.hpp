/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD06-alexandre.flion
** File description:
** KoalaDoctor
*/

#ifndef KOALADOCTOR_HPP_
#define KOALADOCTOR_HPP_

#include <iostream>

#include "SickKoala.hpp"

class KoalaDoctor {
public:
    KoalaDoctor(std::string name);
    ~KoalaDoctor();
    void diagnose(SickKoala *patient);
    void timeCheck();
    void say(std::string input);

    std::string name;
protected:
private:
    bool isWorking;
};

#endif /* !KOALADOCTOR_HPP_ */
