/*
** EPITECH PROJECT, 2021
** Day07A [SSH: 192.168.0.19]
** File description:
** Parts
*/

#include "Parts.hpp"

Parts::Parts(std::string const &serial, bool functional)
{
    this->_serial = serial;
    this->_functional = functional;
    this->_partType = "Parts";
}

bool Parts::isFunctional() const
{
    return this->_functional;
}

std::string Parts::serial() const
{
    return this->_serial;
}

void Parts::informations() const
{
    std::cout << "\t[Parts] " << this->_partType << " " << this->_serial << " status : " << ((this->_functional) ? "OK" : "KO") << std::endl;
}

Legs::Legs(std::string const &serial, bool functional)
{
    this->_serial = serial;
    this->_functional = functional;
    this->_partType = "Legs";
}

Head::Head(std::string const &serial, bool functional)
{
    this->_serial = serial;
    this->_functional = functional;
    this->_partType = "Head";
}

Arms::Arms(std::string const &serial, bool functional)
{
    this->_serial = serial;
    this->_functional = functional;
    this->_partType = "Arms";
}