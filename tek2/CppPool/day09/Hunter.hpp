/*
** EPITECH PROJECT, 2021
** Day09
** File description:
** Hunter
*/

#ifndef HUNTER_HPP_
#define HUNTER_HPP_

#include "Warrior.hpp"

class Hunter : public Warrior {
public:
    Hunter(const std::string &name = "Thor", int level = 40, const std::string &weapon = "sword");

    int RangeAttack();
    void RestorePower();
protected:
    virtual int getStrength() const
    {
        return 9;
    }

    virtual int getStamina() const
    {
        return 9;
    }

    virtual int getIntelligence() const
    {
        return 5;
    }

    virtual int getSpirit() const
    {
        return 6;
    }

    virtual int getAgility() const
    {
        return 25;
    }
private:
};

#endif /* !HUNTER_HPP_ */
