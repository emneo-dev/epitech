/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPD06-alexandre.flion
** File description:
** SickKoala
*/

#ifndef SICKKOALA_HPP_
#define SICKKOALA_HPP_

#include <iostream>

class SickKoala {
public:
    SickKoala(std::string name);
    ~SickKoala();

    void poke();
    bool takeDrug(std::string drug);
    void overDrive(std::string input);
    void say(std::string input);
    std::string getName();

    std::string name;

protected:
private:
};

#endif /* !SICKKOALA_HPP_ */
