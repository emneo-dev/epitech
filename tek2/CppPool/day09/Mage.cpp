#include "Mage.hpp"

Mage::Mage(const std::string &name, int level) :
    Character(name, level)
{
    std::cout << this->_name << " teleported" << std::endl;
}

void Mage::RestorePower()
{
    this->_power = (this->_power + 50 + this->getIntelligence() <= 100) ? this->_power + 50 + this->getIntelligence() : 100;
    std::cout << this->_name << " takes a mana potion" << std::endl;
}

int Mage::CloseAttack()
{
    if (this->Range == AttackRange::RANGE)
        return 0;
    if (this->_power < 10) {
        this->notEnoughPower();
        return 0;
    }
    std::cout << this->_name << " blinks" << std::endl;
    this->_power -= 10;
    this->Range = RANGE;
    return 0;
}

int Mage::RangeAttack()
{
    if (this->_power < 25) {
        this->notEnoughPower();
        return 0;
    }
    std::cout << this->_name << " launches a fire ball" << std::endl;
    this->_power -= 25;
    return 20 + this->getSpirit();
}
