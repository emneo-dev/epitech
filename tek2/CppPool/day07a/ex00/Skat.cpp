/*
** EPITECH PROJECT, 2021
** Day07A
** File description:
** Skat
*/

#include "Skat.hpp"

Skat::Skat(const std::string &name, int stimPaks)
{
    this->_name = name;
    this->_myStock = stimPaks;
}

Skat::~Skat()
{
}

void Skat::status() const
{
    std::cout << "Soldier " << this->_name << " reporting " << this->_myStock << " stimpaks remaining sir!" << std::endl;
}

int &Skat::stimPaks()
{
    return this->_myStock;
}

void Skat::useStimPaks()
{
    if (this->_myStock == 0) {
        std::cout << "Mediiiiiic" << std::endl;
        return;
    }
    std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
    this->_myStock--;
}

const std::string &Skat::name()
{
    return this->_name;
}

void Skat::shareStimPaks(int number, int &stock)
{
    if (number > this->_myStock) {
        std::cout << "Don't be greedy" << std::endl;
        return;
    }
    std::cout << "Keep the change." << std::endl;
    stock += number;
    this->_myStock -= number;
}

void Skat::addStimPaks(unsigned int number)
{
    if (number == 0)
        std::cout << "Hey boya, did you forget something?" << std::endl;
    this->_myStock += number;
}