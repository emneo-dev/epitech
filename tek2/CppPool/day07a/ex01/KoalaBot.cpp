/*
** EPITECH PROJECT, 2021
** Day07A
** File description:
** KoalaBot
*/

#include "KoalaBot.hpp"

KoalaBot::KoalaBot(std::string const &serial)
{
    this->_serial = serial;
    this->_head = Head();
    this->_arms = Arms();
    this->_legs = Legs();
}

void KoalaBot::setParts(Parts const &part)
{
    if (part._partType == "Legs")
        this->_legs = part;
    else if (part._partType == "Arms")
        this->_arms = part;
    else if (part._partType == "Head")
        this->_head = part;
}

void KoalaBot::informations() const
{
    std::cout << "[KoalaBot] " << this->_serial << std::endl;
    this->_arms.informations();
    this->_legs.informations();
    this->_head.informations();
}

bool KoalaBot::status() const
{
    return this->_arms.isFunctional() &&
        this->_legs.isFunctional() &&
        this->_head.isFunctional();
}

void KoalaBot::swapParts(Parts &part)
{
    if (part._partType == "Legs") {
        Parts tmp = this->_legs;
        this->_legs = part;
        part = tmp;
    }
    else if (part._partType == "Arms") {
        Parts tmp = this->_arms;
        this->_arms = part;
        part = tmp;
    }
    else if (part._partType == "Head") {
        Parts tmp = this->_head;
        this->_head = part;
        part = tmp;
    }
}