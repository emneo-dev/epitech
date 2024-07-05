/*
** EPITECH PROJECT, 2021
** Day07M
** File description:
** BorgQueen
*/

#include "BorgQueen.hpp"

namespace Borg
{
    BorgQueen::BorgQueen()
    {
        firePtr = &Ship::fire;
        movePtr = &Ship::move;
        destroyPtr = &Ship::fire;
    }

    void BorgQueen::fire(Borg::Ship *ship, Federation::Starfleet::Ship *target)
    {
        (*ship.*firePtr)(target);
    }

    bool BorgQueen::move(Borg::Ship *ship, Destination dest)
    {
        return (*ship.*movePtr)(dest);
    }

    void BorgQueen::destroy(Borg::Ship *ship, Federation::Ship *target)
    {
        (*ship.*destroyPtr)(target);
    }
}