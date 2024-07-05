/*
** EPITECH PROJECT, 2021
** Day07A
** File description:
** Phaser
*/

#include <iostream>

#include "Phaser.hpp"
#include "Sounds.hpp"

const int Phaser::Empty = 0;

Ammo::Ammo(Phaser::AmmoType type)
{
    this->type = type;
    this->next = nullptr;
}

Phaser::Phaser(int maxAmmo, AmmoType type) :
    m_maxAmmo(maxAmmo)
{
    this->m_ammo = nullptr;
    for (int i = 0; i < maxAmmo; i++)
        this->addAmmo(type);
    this->m_defaultType = type;
}

Phaser::~Phaser()
{}

void Phaser::reload()
{
    std::cout << "Reloading..." << std::endl;
    this->ejectClip();
    for (int i = 0; i < this->m_maxAmmo; i++)
        addAmmo(this->m_defaultType);
}

void Phaser::fire()
{
    if (this->getCurrentAmmos() == Phaser::Empty) {
        std::cout << "Clip empty, please reload" << std::endl;
        return;
    }
    Ammo *current = this->m_ammo;
    if (current->type == Phaser::AmmoType::Plasma)
        std::cout << Sounds::Plasma << std::endl;
    else if (current->type == Phaser::AmmoType::Regular)
        std::cout << Sounds::Regular << std::endl;
    else if (current->type == Phaser::AmmoType::Rocket)
        std::cout << Sounds::Rocket << std::endl;
    this->m_ammo = current->next;
    delete current;
}

void Phaser::ejectClip()
{
    if (this->m_ammo == nullptr)
        return;
    Ammo *current = this->m_ammo;
    while (current) {
        Ammo *tmp = current->next;
        delete current;
        current = tmp;
    }
    this->m_ammo = nullptr;
}

void Phaser::addAmmo(AmmoType type)
{
    if (this->m_ammo == nullptr) {
        this->m_ammo = new Ammo(type);
        return;
    }
    if (this->getCurrentAmmos() >= this->m_maxAmmo) {
        std::cout << "Clip full" << std::endl;
        return;
    }
    Ammo *current = this->m_ammo;
    for (; current->next; current = current->next);
    current->next = new Ammo(type);
}

int Phaser::getCurrentAmmos() const
{
    int count = 0;
    Ammo *current = this->m_ammo;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}