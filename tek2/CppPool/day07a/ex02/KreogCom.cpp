/*
** EPITECH PROJECT, 2021
** Day07A
** File description:
** KreogCom
*/

#include <iostream>

#include "KreogCom.hpp"

KreogCom::KreogCom(int x, int y, int serial) : m_serial(serial), _x(x), _y(y), _next(nullptr)
{
    std::cout << "KreogCom " << serial << " initialized" << std::endl;
}

KreogCom::~KreogCom()
{
    std::cout << "KreogCom " << this->m_serial << " shutting down" << std::endl;
}

void KreogCom::addCom(int x, int y, int serial)
{
    KreogCom *newNode = new KreogCom(x, y, serial);
    newNode->_next = this->_next;
    this->_next = newNode;
}

void KreogCom::removeCom()
{
    KreogCom *toRemove;
    if (this->_next != nullptr) {
        toRemove = this->_next;
        this->_next = this->_next->_next;
        std::cout << "KreogCom " << toRemove->m_serial << " shutting down" << std::endl;
    }
}

KreogCom *KreogCom::getCom()
{
    return this->_next;
}

void KreogCom::ping() const
{
    std::cout << "KreogCom " << this->m_serial << " currently at " << this->_x << " " << this->_y << std::endl;
}

void KreogCom::locateSquad() const
{
    KreogCom *current = this->_next;
    while (current != nullptr) {
        current->ping();
        current = current->_next;
    }
    this->ping();
}