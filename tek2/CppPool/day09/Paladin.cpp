#include "Paladin.hpp"


Paladin::Paladin(const std::string &name, int level, const std::string &weapon) :
    Character(name, level),
    Warrior(name, 42, weapon),
    Priest(name, level)
{
    std::cout << "the light falls on " << this->Warrior::_name << std::endl;
}

int Paladin::intercept()
{
    if (this->Warrior::Range == AttackRange::CLOSE)
        return 0;
    if (this->Warrior::_power < 10) {
        this->Warrior::notEnoughPower();
        return 0;
    }
    std::cout << this->Warrior::_name << " intercepts" << std::endl;
    this->Warrior::_power -= 10;
    return 0;
}
