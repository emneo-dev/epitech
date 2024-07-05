/*
** EPITECH PROJECT, 2021
** Day08
** File description:
** DroidMemory
*/

#include <random>
#include <iostream>

#include "DroidMemory.hpp"

DroidMemory::DroidMemory() :
    Fingerprint(random()),
    Exp(0)
{}

DroidMemory::~DroidMemory()
{}

size_t DroidMemory::getExp() const
{
    return this->Exp;
}

size_t DroidMemory::getFingerprint() const
{
    return this->Fingerprint;
}

void DroidMemory::setExp(size_t value)
{
    this->Exp = value;
}

void DroidMemory::setFingerprint(size_t value)
{
    this->Fingerprint = value;
}

DroidMemory &DroidMemory::operator<<(const DroidMemory &memory)
{
    this->Exp += memory.Exp;
    this->Fingerprint ^= memory.Fingerprint;
    return *this;
}

DroidMemory &DroidMemory::operator>>(DroidMemory &memory) const
{
    memory.Exp += this->Exp;
    memory.Fingerprint ^= this->Fingerprint;
    return memory;
}

DroidMemory &DroidMemory::operator+=(const DroidMemory &memory)
{
    return *this << memory;
}

DroidMemory &DroidMemory::operator+=(const size_t &experience)
{
    this->Exp += experience;
    this->Fingerprint ^= experience;
    return *this;
}

DroidMemory DroidMemory::operator+(const DroidMemory &memory) const
{
    DroidMemory m;

    m.Exp = this->Exp + memory.Exp;
    m.Fingerprint = this->Fingerprint ^ memory.Fingerprint;
    return m;
}

DroidMemory DroidMemory::operator+(const size_t &experience) const
{
    DroidMemory m;

    m.Exp = this->Exp + experience;
    m.Fingerprint = this->Fingerprint ^ experience;
    return m;
}

std::ostream &operator<<(std::ostream &os, const DroidMemory &memory)
{
    return os << "DroidMemory '" << memory.getFingerprint() << "', " << memory.getExp();
}
