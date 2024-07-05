//
// Created by huntears on 1/18/21.
//

#include "Toy.hpp"

Toy::ToyType Toy::getType() const {
    return this->_type;
}

const std::string &Toy::getName() const {
    return this->_name;
}

void Toy::setName(const std::string &name) {
    this->_name = name;
}

bool Toy::setAscii(const std::string &filename) {
    return this->_picture.getPictureFromFile(filename);
}

const std::string &Toy::getAscii() const {
    return this->_picture.data;
}

Toy::Toy() :
    _type(ToyType::BASIC_TOY),
    _name("toy")
{
    this->_picture.data = "";
}

Toy::Toy(Toy::ToyType type, const std::string &name, const std::string &filename) :
    _type(type),
    _name(name)
{
    this->_picture.getPictureFromFile(filename);
}
