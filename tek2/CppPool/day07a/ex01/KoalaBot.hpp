/*
** EPITECH PROJECT, 2021
** Day07A
** File description:
** KoalaBot
*/

#ifndef KOALABOT_HPP_
#define KOALABOT_HPP_

#include <iostream>

#include "Parts.hpp"

class KoalaBot {
public:
    KoalaBot(std::string const &serial = "Bob-01");

    void setParts(Parts const &part);
    void swapParts(Parts &part);
    void informations() const;
    bool status() const;
protected:
private:
    std::string _serial;
    Parts _legs;
    Parts _arms;
    Parts _head;
};

#endif /* !KOALABOT_HPP_ */
