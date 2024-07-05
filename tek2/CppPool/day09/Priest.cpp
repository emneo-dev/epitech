#include "Priest.hpp"


Priest::Priest(const std::string &name, int level) :
    Character(name, level),
    Mage(name, level)
{
    std::cout << this->_name << " enters in the order" << std::endl;
}

void Priest::Heal()
{
    this->_pv = (this->_pv >= 70) ? 100 : this->_pv + 70;
    std::cout << this->_name << " casts a little heal spell" << std::endl;
}

int Priest::CloseAttack()
{
    if (this->Range == RANGE)
        return 0;
    if (this->_power < 10) {
        this->notEnoughPower();
        return 0;
    }
    std::cout << this->_name << " uses a spirit explosion" << std::endl;
    this->_power -= 10;
    this->Range = RANGE;
    return 10 + this->getSpirit();
}
