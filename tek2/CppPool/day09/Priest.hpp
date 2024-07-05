/*
** EPITECH PROJECT, 2021
** Day09
** File description:
** Priest
*/

#ifndef PRIEST_HPP_
#define PRIEST_HPP_

#include "Mage.hpp"

class Priest : public Mage{
public:
    Priest(const std::string &name = "Iopi", int level = 84);

    void Heal();
    int CloseAttack();
protected:
    virtual int getStrength() const
    {
        return 4;
    }

    virtual int getStamina() const
    {
        return 4;
    }

    virtual int getIntelligence() const
    {
        return 42;
    }

    virtual int getSpirit() const
    {
        return 21;
    }

    virtual int getAgility() const
    {
        return 2;
    }
private:
};

#endif /* !PRIEST_HPP_ */
