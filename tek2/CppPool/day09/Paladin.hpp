/*
** EPITECH PROJECT, 2021
** Day09
** File description:
** Paladin
*/

#ifndef PALADIN_HPP_
#define PALADIN_HPP_

#include "Warrior.hpp"
#include "Priest.hpp"

class Paladin : public Warrior, public Priest{
public:
    Paladin(const std::string &name = "Phiste", int level = 42, const std::string &weapon = "hammer");

    int intercept();
    using Priest::RangeAttack;
    using Warrior::CloseAttack;
    using Priest::Heal;
    using Warrior::RestorePower;
    using Warrior::TakeDamage;
protected:
    virtual int getStrength() const
    {
        return 9;
    }

    virtual int getStamina() const
    {
        return 10;
    }

    virtual int getIntelligence() const
    {
        return 10;
    }

    virtual int getSpirit() const
    {
        return 10;
    }

    virtual int getAgility() const
    {
        return 2;
    }
private:
};

#endif /* !PALADIN_HPP_ */
