/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPrush2-alexandre.descoins
** File description:
** Wrap
*/

#include <iostream>
#include "Wrap.hpp"

Wrap::Wrap(Object::objType type, std::string const &title) : Object(type, title)
{
    m_isOpen = false;
    m_content = nullptr;
}

Object *Wrap::getContent() const
{
    return (m_content);
}

bool Wrap::isOpen() const
{
  return (m_isOpen);
}

Object *Wrap::takeContent()
{
	Object *extracted = m_content;

	if (!m_content) {
		std::cerr << "This box is empty!" << std::endl;
		return (extracted);
	}
	m_content = nullptr;
	return (extracted);
}

Object *Wrap::isTaken()
{
    if (m_taken) {
		std::cerr << "This item is already taken by someone!" << std::endl;
        return (nullptr);
	}
    std::cout << "whistles while working" << std::endl;
    m_taken = true;
	return (this);
}

Wrap::~Wrap()
{
}

void Wrap::openMe()
{
	this->m_isOpen = true;
}

void Wrap::closeMe()
{
	this->m_isOpen = false;
}

bool Wrap::wrapMeThat(Object *obj)
{
	if (this->m_content) {
		return false;
	}
	this->m_content = obj;
	std::cout << "tuuuut tuuut tuut" << std::endl;
	return true;
}