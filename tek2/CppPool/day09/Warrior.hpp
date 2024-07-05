/*
** EPITECH PROJECT, 2021
** Day09
** File description:
** Warrior
*/

#ifndef WARRIOR_HPP_
#define WARRIOR_HPP_

#include "Character.hpp"

class Warrior : virtual public Character{
public:
    Warrior(const std::string &name = "Thor", int level = 42, const std::string &weapon = "hammer", bool display = 1);

    int CloseAttack();
    int RangeAttack();
    using Character::RestorePower;
protected:
    virtual int getStrength() const
    {
        return 12;
    }

    virtual int getStamina() const
    {
        return 12;
    }

    virtual int getIntelligence() const
    {
        return 6;
    }

    virtual int getSpirit() const
    {
        return 5;
    }

    virtual int getAgility() const
    {
        return 7;
    }
private:
    const std::string weapon;
};

#endif /* !WARRIOR_HPP_ */
