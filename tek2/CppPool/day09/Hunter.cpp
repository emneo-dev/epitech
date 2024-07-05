#include "Hunter.hpp"

Hunter::Hunter(const std::string &name, int level, const std::string &weapon) :
    Character(name, level),
    Warrior(name, level, weapon, false)
{
    std::cout << this->_name << " is born from a tree" << std::endl;
}

int Hunter::RangeAttack()
{
    if (this->_power < 25) {
        this->notEnoughPower();
        return 0;
    }
    std::cout << this->_name << " uses his bow" << std::endl;
    this->_power -= 25;
    return 0;
}

void Hunter::RestorePower()
{
    this->_power = 100;
    std::cout << this->_name << " meditates" << std::endl;
}
