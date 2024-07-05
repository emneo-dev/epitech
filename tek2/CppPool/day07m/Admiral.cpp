/*
** EPITECH PROJECT, 2021
** Day07M
** File description:
** *
*/

#include "Admiral.hpp"

namespace Federation
{
    namespace Starfleet
    {
        Admiral::Admiral(std::string name)
        {
            this->_name = name;
            firePtr = &Ship::fire;
            movePtr = &Ship::move;
            std::cout << "Admiral " << this->_name << " ready for action." << std::endl;
        }

        void Admiral::fire(Federation::Starfleet::Ship *ship, Borg::Ship *target)
        {
            std::cout << "On order from Admiral " << this->_name << ":" << std::endl;
            (*ship.*firePtr)(target);
        }

        bool Admiral::move(Federation::Starfleet::Ship *ship, Destination d)
        {
            return (*ship.*movePtr)(d);
        }
    }
}