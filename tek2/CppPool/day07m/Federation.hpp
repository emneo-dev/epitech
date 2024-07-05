/*
** EPITECH PROJECT, 2021
** Day07M
** File description:
** Federation
*/

#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_

#include <iostream>

#include "WarpSystem.hpp"
#include "Destination.hpp"
#include "Borg.hpp"

namespace Borg
{
    class Ship;
}

namespace Federation
{
    namespace Starfleet
    {
        class Captain
        {
        private:
            std::string _name;
            int _age;
        public:
            Captain(std::string name);

            std::string getName();
            int getAge();
            void setAge(int age);
        };

        class Ensign
        {
        private:
            std::string _name;
        public:
            explicit Ensign(std::string name);
        };

        class Ship
        {
        private:
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core *core;
            Captain *captain;
        public:
            Ship(int length, int width, std::string name, short maxWarp, int torpedo = 0);
            Ship();

            void checkCore();
            void setupCore(WarpSystem::Core *core);
            void promote(Captain *captain);
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
            int _photonTorpedo;
        public:
            int getShield();
            void setShield(int shield);
            int getTorpedo();
            void setTorpedo(int torpedo);
            void fire(Borg::Ship *target);
            void fire(int torpedoes, Borg::Ship *target);
        };
    }

    class Ship
    {
    private:
        int _length;
        int _width;
        std::string _name;
        short _maxWarp;
        WarpSystem::Core *core;
    public:
        Ship(int length, int width, std::string name);

        void checkCore();
        void setupCore(WarpSystem::Core *core);
        WarpSystem::Core *getCore();
    private:
        Destination _location;
        Destination _home;
    public:
        bool move(int warp, Destination d);
        bool move(int warp);
        bool move(Destination d);
        bool move();
    };
}

#endif /* !FEDERATION_HPP_ */
