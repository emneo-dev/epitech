/*
** EPITECH PROJECT, 2021
** Day09
** File description:
** Mage
*/

#ifndef MAGE_HPP_
#define MAGE_HPP_

#include "Character.hpp"

class Mage : virtual public Character{
public:
    Mage(const std::string &name = "Fluffy", int level = 40);

    void RestorePower();
    int CloseAttack();
    int RangeAttack();

protected:
    virtual int getStrength() const
    {
        return 6;
    }

    virtual int getStamina() const
    {
        return 6;
    }

    virtual int getIntelligence() const
    {
        return 12;
    }

    virtual int getSpirit() const
    {
        return 11;
    }

    virtual int getAgility() const
    {
        return 7;
    }
private:
};

#endif /* !MAGE_HPP_ */
