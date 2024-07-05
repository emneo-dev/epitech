#include "Warrior.hpp"

Warrior::Warrior(const std::string &name, int level, const std::string &weapon, bool display) :
    Character(name, level),
    weapon(weapon)
{
    if (display)
        std::cout << "I'm " << this->_name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl; // WTF is this shit ?
}

int Warrior::CloseAttack()
{
    if (this->Range == AttackRange::RANGE)
        return 0;
    if (this->_power < 30) {
        this->notEnoughPower();
        return 0;
    }
    std::cout << this->_name << " strikes with his " << this->weapon <<std::endl;
    this->_power -= 30;
    return 20 + this->getStrength();
}

int Warrior::RangeAttack()
{
    if (this->Range == AttackRange::CLOSE)
        return 0;
    if (this->_power < 10) {
        this->notEnoughPower();
        return 0;
    }
    std::cout << this->_name << " intercepts" << std::endl;
    this->_power -= 10;
    this->Range = CLOSE;
    return 0;
}
