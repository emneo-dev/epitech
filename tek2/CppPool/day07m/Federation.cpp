/*
** EPITECH PROJECT, 2021
** Day07M
** File description:
** Federation
*/

#include "Federation.hpp"

namespace Federation
{
    namespace Starfleet
    {
        Captain::Captain(std::string name)
        {
            this->_name = name;
            this->_age = 0;
        }

        std::string Captain::getName()
        {
            return this->_name;
        }

        int Captain::getAge()
        {
            return this->_age;
        }

        void Captain::setAge(int age)
        {
            this->_age = age;
        }

        Ensign::Ensign(std::string name)
        {
            this->_name = name;
            std::cout << "Ensign " << name << ", awaiting orders." << std::endl;
        }

        Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo)
        {
            this->_length = length;
            this->_width = width;
            this->_name = name;
            this->_maxWarp = maxWarp;
            this->_home = Destination::EARTH;
            this->_photonTorpedo = torpedo;
            this->_shield = 100;
            std::cout << "The ship USS " << name << " has been finished." << std::endl <<
            "It is " << length << " m in length and " << width << " m in width." << std::endl <<
            "It can go to Warp " << maxWarp << "!" << std::endl;
            if (torpedo)
                std::cout << "Weapons are set: " << torpedo << " torpedoes ready." << std::endl;
        }

        Ship::Ship()
        {
            this->_length = 289;
            this->_width = 132;
            this->_name = "Entreprise";
            this->_maxWarp = 6;
            this->_home = Destination::EARTH;
            this->_photonTorpedo = 0;
            this->_shield = 100;
        }

        void Ship::checkCore()
        {
            if (core->checkReactor()->isStable())
                std::cout << "USS " << this->_name << ": The core is stable at the time." << std::endl;
            else
                std::cout << "USS " << this->_name << ": The core is unstable at the time." << std::endl;
        }

        void Ship::setupCore(WarpSystem::Core *core)
        {
            this->core = core;
            std::cout << "USS " << this->_name << ": The core is set." << std::endl;
        }

        void Ship::promote(Captain *captain)
        {
            this->captain = captain;
            std::cout << captain->getName() << ": I'm glad to be the captain of the USS " << this->_name << "." << std::endl;
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

        int Ship::getTorpedo()
        {
            return this->_photonTorpedo;
        }

        void Ship::setTorpedo(int torpedo)
        {
            this->_photonTorpedo = torpedo;
        }

        void Ship::fire(int torpedoes, Borg::Ship *target)
        {
            if (this->_photonTorpedo == 0) {
                std::cout << this->_name << ": No more torpedo to fire, " << this->captain->getName() << "!" << std::endl;
            }
            if (torpedoes > this->_photonTorpedo) {
                std::cout << this->_name << ": No enough torpedoes to fire, " << this->captain->getName() << "!" << std::endl;
                return;
            }
            int targetShield = target->getShield();
            targetShield -= torpedoes * 50;
            target->setShield((targetShield < 0) ? 0 : targetShield);
            this->_photonTorpedo -= torpedoes;
            std::cout << this->_name << ": Firing on target. " << this->_photonTorpedo << " torpedoes remaining." << std::endl;
        }

        void Ship::fire(Borg::Ship *target)
        {
            return fire(1, target);
        }
    }

    Ship::Ship(int length, int width, std::string name)
    {
        this->_length = length;
        this->_width = width;
        this->_name = name;
        this->_maxWarp = 1;
        this->_home = Destination::VULCAN;
        std::cout << "The independent ship " << name << " just finished its construction." << std::endl <<
        "It is " << length << " m in length and " << width << " m in width." << std::endl;
    }

    void Ship::checkCore()
    {
        if (core->checkReactor()->isStable())
            std::cout << this->_name << ": The core is stable at the time." << std::endl;
        else
            std::cout << this->_name << ": The core is unstable at the time." << std::endl;
    }

    void Ship::setupCore(WarpSystem::Core *core)
    {
        this->core = core;
        std::cout << this->_name << ": The core is set." << std::endl;
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

    WarpSystem::Core *Ship::getCore()
    {
        return this->core;
    }
}