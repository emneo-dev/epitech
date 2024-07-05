/*
** EPITECH PROJECT, 2021
** Day07M
** File description:
** BorgQueen
*/

#ifndef BORGQUEEN_HPP_
#define BORGQUEEN_HPP_

#include "Federation.hpp"

namespace Borg
{
    class BorgQueen {
    public:
        BorgQueen();
        void fire(Borg::Ship *ship, Federation::Starfleet::Ship *target);
        bool move(Borg::Ship *ship, Destination dest);
        void destroy(Borg::Ship *ship, Federation::Ship *target);

        bool (Borg::Ship::*movePtr)(Destination);
        void (Borg::Ship::*firePtr)(Federation::Starfleet::Ship *);
        void (Borg::Ship::*destroyPtr)(Federation::Ship *);
    protected:
    private:
    };
}

#endif /* !BORGQUEEN_HPP_ */
