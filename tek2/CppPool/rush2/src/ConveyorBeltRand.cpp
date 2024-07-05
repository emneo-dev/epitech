/*
** EPITECH PROJECT, 2021
** ConveyorBeltRand
** File description:
** ConveyorBeltRand
*/

#include "ConveyorBeltRand.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"

ConveyorBeltRand::ConveyorBeltRand()
{}

ConveyorBeltRand::~ConveyorBeltRand()
{}

void ConveyorBeltRand::IN()
{
    if (this->m_content) {
        std::cerr << "The conveyor is already used !" << std::endl;
        return;
    }
    if (random() % 2)
        m_content = new Box;
    else
        m_content = new GiftPaper;
    m_name = m_content->getType();
}

void ConveyorBeltRand::serialization()
{
    if (this->m_content != nullptr)
        std::cout << this->m_content->xmlObject() << std::endl;
}