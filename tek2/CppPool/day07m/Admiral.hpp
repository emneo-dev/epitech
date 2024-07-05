/*
** EPITECH PROJECT, 2021
** Day07M
** File description:
** Admiral
*/

#ifndef ADMIRAL_HPP_
#define ADMIRAL_HPP_

#include "Federation.hpp"


namespace Federation
{
    namespace Starfleet
    {
        class Admiral {
        public:
            Admiral(std::string name);
            void fire(Federation::Starfleet::Ship *ship, Borg::Ship *target);
            bool move(Federation::Starfleet::Ship *ship, Destination dest);

            bool (Federation::Starfleet::Ship::*movePtr)(Destination);
            void (Federation::Starfleet::Ship::*firePtr)(Borg::Ship *);
        protected:
        private:
            std::string _name;
        };
    }
}

#endif /* !ADMIRAL_HPP_ */
