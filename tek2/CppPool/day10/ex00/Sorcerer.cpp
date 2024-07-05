//
// Created by huntears on 1/15/21.
//

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(const std::string &name, const std::string &title) :
    _name(name),
    _title(title) {
    std::cout << name << ", " << title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer() {
    std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same!" << std::endl;
}

const std::string &Sorcerer::getName() const {
    return _name;
}

const std::string &Sorcerer::getTitle() const {
    return _title;
}

void Sorcerer::polymorph(const Victim &victim) const {
    victim.getPolymorphed();
}

std::ostream &operator<<(std::ostream &os, const Sorcerer &obj) {
    return os << "I am " << obj.getName() << ", " << obj.getTitle() << ", and I like ponies!" << std::endl;
}
