/*
** EPITECH PROJECT, 2021
** Day07M
** File description:
** Borg
*/

#ifndef BORG_HPP_
#define BORG_HPP_

#include "WarpSystem.hpp"
#include "Destination.hpp"
#include "Federation.hpp"

namespace Federation
{
    namespace Starfleet
    {
        class Ship;
    }
    class Ship;
}

namespace Borg
{
    class Ship
    {
    private:
        int _side;
        short _maxWarp;
        WarpSystem::Core *core;
    public:
        Ship(int weaponFrequency = 20, short repair = 3);

        void checkCore();
        void setupCore(WarpSystem::Core *core);
    private:
        Destination _location;
        Destination _home;
    public:
        bool move(int warp, Destination d);
        bool move(int warp);
        bool move(Destination d);
        bool move();
    private:
        int _shield;
        int _weaponFrequency;
        short _repair;
    public:
        int getShield();
        void setShield(int shield);
        int getWeaponFrequency();
        void setWeaponFrequency(int frequency);
        int getRepair();
        void setRepair(short repair);

        void fire(Federation::Starfleet::Ship *target);
        void fire(Federation::Ship *target);
        void repair();
    };
}

#endif /* !BORG_HPP_ */
