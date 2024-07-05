/*
** EPITECH PROJECT, 2021
** Day09
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <iostream>

class Character {
public:
    enum AttackRange {
        CLOSE,
        RANGE
    };

    Character(const std::string &name = "Kreog", int level = 1);

    const std::string &getName() const;
    int getLvl() const;
    int getPv() const;
    int getPower() const;
    int CloseAttack();
    int RangeAttack();
    void Heal();
    void RestorePower();
    void TakeDamage(int damage);
    AttackRange Range = AttackRange::CLOSE;
protected:
    void notEnoughPower() const;
    const std::string _name;
    int _pv = 100;
    int _power = 100;
    int _lvl;
    virtual int getStrength() const
    {
        return 5;
    }

    virtual int getStamina() const
    {
        return 5;
    }

    virtual int getIntelligence() const
    {
        return 5;
    }

    virtual int getSpirit() const
    {
        return 5;
    }

    virtual int getAgility() const
    {
        return 5;
    }
private:
};

#endif /* !CHARACTER_HPP_ */
