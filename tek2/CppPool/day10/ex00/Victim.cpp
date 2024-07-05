//
// Created by huntears on 1/15/21.
//

#include "Victim.hpp"

const std::string &Victim::getName() const {
    return _name;
}

Victim::Victim(const std::string &name) :
    _name(name){
    std::cout << "Some random victim called " << name << " just popped!" << std::endl;
}

Victim::~Victim() {
    std::cout << "Victim " << this->_name << " just died for no apparent reason!" << std::endl;
}

void Victim::getPolymorphed() const {
    std::cout << this->_name << " has been turned into a cute little sheep!" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Victim &victim) {
    return os << "I'm " << victim.getName() << " and I like otters!" << std::endl;
}