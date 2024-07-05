#include "Character.hpp"

int Character::getPv() const {
    return this->_pv;
}

Character::Character(const std::string &name, int level) :
    _name(name),
    _lvl(level)
{
    std::cout << this->_name << " Created" << std::endl;
}

const std::string &Character::getName() const
{
    return this->_name;
}

int Character::getLvl() const
{
    return this->_lvl;
}

int Character::getPower() const
{
    return this->_power;
}

void Character::notEnoughPower() const
{
    std::cout << this->_name << " out of power" << std::endl;
}

int Character::CloseAttack()
{
    if (this->Range == AttackRange::RANGE)
        return 0;
    if (this->_power < 10) {
        this->notEnoughPower();
        return 0;
    }
    std::cout << this->_name << " strikes with a wooden stick" << std::endl;
    this->_power -= 10;
    return 10 + this->getStrength();
}

int Character::RangeAttack()
{
    if (this->_power < 10) {
        this->notEnoughPower();
        return 0;
    }
    std::cout << this->_name << " tosses a stone" << std::endl;
    this->_power -= 10;
    return 5 + this->getStrength();
}

void Character::Heal()
{
    this->_pv = (this->_pv >= 50) ? 100 : this->_pv + 50;
    std::cout << this->_name << " takes a potion" << std::endl;
}

void Character::RestorePower()
{
    this->_power = 100;
    std::cout << this->_name << " eats" << std::endl;
}

void Character::TakeDamage(int damage)
{
    this->_pv -= damage;
    if (this->_pv <= 0)
        std::cout << this->_name << " out of combat" << std::endl;
    else
        std::cout << this->_name << " takes " << damage << " damage" << std::endl;
}
