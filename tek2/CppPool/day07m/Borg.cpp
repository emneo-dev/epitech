/*
** EPITECH PROJECT, 2021
** Day07M
** File description:
** Borg
*/

#include <iostream>

#include "Borg.hpp"

namespace Borg
{
    Ship::Ship(int weaponFrequency, short repair)
    {
        this->_side = 300;
        this->_maxWarp = 9;
        this->_home = Destination::UNICOMPLEX;
        this->_weaponFrequency = weaponFrequency;
        this->_repair = repair;
        this->_shield = 100;
        std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl <<
        "Your biological characteristics and technologies will be assimilated." << std::endl <<
        "Resistance is futile." << std::endl;
    }

    void Ship::checkCore()
    {
        if (core->checkReactor()->isStable())
            std::cout << "Everything is in order." << std::endl;
        else
            std::cout << "Critical failure imminent." << std::endl;
    }

    void Ship::setupCore(WarpSystem::Core *core)
    {
        this->core = core;
    }

    bool Ship::move(int warp, Destination d)
    {
        if (warp > this->_maxWarp || d == this->_location || this->core->checkReactor()->isStable() == false)
            return false;
        this->_location = d;
        return true;
    }

    bool Ship::move(int warp)
    {
        if (warp > this->_maxWarp || this->core->checkReactor()->isStable() == false)
            return false;
        this->_location = this->_home;
        return true;
    }

    bool Ship::move(Destination d)
    {
        if (d == this->_location || this->core->checkReactor()->isStable() == false)
            return false;
        this->_location = d;
        return true;
    }

    bool Ship::move()
    {
        if (this->core->checkReactor()->isStable() == false)
            return false;
        this->_location = this->_home;
        return true;
    }

    int Ship::getShield()
    {
        return this->_shield;
    }

    void Ship::setShield(int shield)
    {
        this->_shield = shield;
    }

    int Ship::getWeaponFrequency()
    {
        return this->_weaponFrequency;
    }

    void Ship::setWeaponFrequency(int weaponFrequency)
    {
        this->_weaponFrequency = weaponFrequency;
    }

    int Ship::getRepair()
    {
        return this->_repair;
    }

    void Ship::setRepair(short repair)
    {
        this->_repair = repair;
    }

    void Ship::fire(Federation::Starfleet::Ship *target)
    {
        int targetShield = target->getShield();
        targetShield -= this->_weaponFrequency;
        target->setShield((targetShield < 0) ? 0 : targetShield);
        std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
    }

    void Ship::fire(Federation::Ship *target)
    {
        target->getCore()->checkReactor()->setStability(false);
        std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
    }

    void Ship::repair()
    {
        if (this->_repair <= 0) {
            std::cout << "Energy cells depleted, shield weakening." << std::endl;
            return;
        }
        std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions." << std::endl;
        this->_repair--;
        this->_shield = 100;
    }
}