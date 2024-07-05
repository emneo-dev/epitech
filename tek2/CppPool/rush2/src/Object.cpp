/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPrush2-alexandre.descoins
** File description:
** Object
*/

#include "Toy.hpp"
#include "Object.hpp"

Object::Object(objType type, std::string const &title)
{
    this->m_taken = false;
    this->m_type = type;
    this->m_title = title;
}

Object::~Object()
{
}

std::string Object::getTitle() const
{
    return (m_title);
}

Object::objType Object::getType() const
{
    return (m_type);
}

bool Object::getTaken() const
{
    return (m_taken);
}

void Object::setTaken(bool take)
{
    m_taken = take;
}

const std::string Object::getTypeName() const
{
    if (m_type == TOY)
        return ("toy");
    else if (m_type == BOX)
        return ("box");
    else if (m_type == PAPER)
        return ("paper");
    return ("unknown");
}

std::ostream &operator<<(std::ostream &os, const Object &obj)
{
    os << "Oh look, a " << obj.getTypeName() << ". Its labelled " << obj.getTitle() << std::endl;
    return os;
}

void Object::openMe()
{
    std::cerr << "Member function openMe not implemented" << std::endl;
}

void Object::closeMe()
{
    std::cerr << "Member function openMe not implemented" << std::endl;
}

bool Object::isOpen() const
{
    std::cerr << "Member function openMe not implemented" << std::endl;
    return (false);
}

bool Object::wrapMeThat(Object *o)
{
    (void) o;
    std::cerr << "Member function wrapMeThat not implemented" << std::endl;
    return (false);
}

Object *Object::getContent() const
{
    std::cerr << "Member function getContent not implemented" << std::endl;
    return nullptr;
}

std::string Object::xmlObject() const
{
    if (this->m_type == TOY)
        return std::string("<" + enumToStringType(this->m_type) + ">" + this->m_title + "</" + enumToStringType(this->m_type) + ">");
    return std::string("<" + enumToStringType(this->m_type) + ">" + (this->getContent() ? this->getContent()->xmlObject() : "") + "</" + enumToStringType(this->m_type) + ">");
}

std::string Object::enumToStringType(objType obj) const
{
    const Toy *yes = (const Toy *) &(*this);
    switch (obj) {
    case TOY:
        return yes->getToyType();
    case BOX:
        return "Box";
    case PAPER:
        return "GiftPaper";
    }
    return "";
}