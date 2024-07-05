/*
** EPITECH PROJECT, 2021
** Day08
** File description:
** Droid
*/

#include "Droid.hpp"

Droid::Droid(std::string serial) :
    _id(serial),
    BattleData(new DroidMemory())
{
    _status = new std::string("Standing by");
    std::cout << "Droid '" << this->getId() << "' Activated" << std::endl;
}

Droid::Droid(const Droid &other) :
    _energy(other.getEnergy()),
    _id(other.getId()),
    _attack(other.getAttack()),
    _toughness(other.getToughness()),
    BattleData(new DroidMemory(*(other.BattleData)))
{
    _status = new std::string(*other.getStatus());
    std::cout << "Droid '" << this->getId() << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    std::cout << "Droid '" << this->getId() << "' Destroyed" << std::endl;
    delete _status;
    delete BattleData;
}

const std::string &Droid::getId() const
{
    return _id;
}

size_t Droid::getEnergy() const
{
    return _energy;
}

size_t Droid::getAttack() const
{
    return _attack;
}

size_t Droid::getToughness() const
{
    return _toughness;
}

std::string *Droid::getStatus() const
{
    return _status;
}

void Droid::setId(const std::string &id)
{
    _id = id;
}

void Droid::setEnergy(size_t energy)
{
    _energy = energy;
}

void Droid::setStatus(std::string *status)
{
    delete _status;
    _status = new std::string(*status);
}

Droid &Droid::operator=(const Droid &other)
{
    if (&other != this) {
        setStatus(other.getStatus());
        setEnergy(other.getEnergy());
        setId(other.getId());
    }
    return *this;
}

bool Droid::operator!=(const Droid &rhs) const
{
    return (!(*this == rhs));
}

bool Droid::operator==(const Droid &rhs) const
{
    return (_status == rhs.getStatus());
}

Droid &Droid::operator<<(size_t &energy)
{
    if (this->_energy < 100) {
        int take = std::min(100 - this->_energy, energy);
        this->_energy += take;
        energy -= take;
    }
    return *this;
}

std::ostream & operator<<(std::ostream & os, const Droid & droid)
{
    if (droid.getEnergy() > 100)
        return(os << "Droid '" << droid.getId() << "', " << *(droid.getStatus()) << ", 100");
    else
        return(os << "Droid '" << droid.getId() << "', " << *(droid.getStatus()) << ", " << droid.getEnergy());
}
