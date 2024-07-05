/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPrush2-alexandre.descoins
** File description:
** PapaXmaxConveyorBelt
*/

#include "GiftPaper.hpp"
#include "Box.hpp"
#include "PapaXmasConveyorBelt.hpp"
#include <fstream>

PapaXmasConveyorBelt::PapaXmasConveyorBelt() :
    m_content(nullptr),
    m_name(""),
    nbrGift(1)
{}

PapaXmasConveyorBelt::~PapaXmasConveyorBelt()
{
    delete this->m_content;
}

Object *PapaXmasConveyorBelt::Take()
{
    if (!this->m_content) {
        std::cerr << "Nothing to take, the conveyor is empty!" << std::endl;
        return nullptr;
    }
    Object *toReturn = m_content;
    m_content->isTaken();
    m_content->setTaken(true);
    m_content = nullptr;
    m_name = "";
    return toReturn;
}

bool PapaXmasConveyorBelt::Put(Object *obj)
{
    if (this->m_content) {
        std::cout << "Conveyor already full!" << std::endl;
        return false;
    }
    this->m_content = obj;
    this->m_name = obj->getTitle();
    return true;
}

std::string PapaXmasConveyorBelt::Look() const
{
    return (m_name);
}

void PapaXmasConveyorBelt::IN()
{
    int item = std::rand() % 2;

    if (m_content)
        std::cerr << "Please empty the table before asking for wrap!" << std::endl;
    if (item == 0)
        m_content = new Box;
    if (item == 1)
        m_content = new GiftPaper;
}

void PapaXmasConveyorBelt::generateXML(Object *objGift)
{
    std::string str = "gift" + std::to_string(this->nbrGift) + ".xml"; 
    std::ofstream outfile(str);

    this->nbrGift += 1;
    std::cout << objGift->xmlObject() << std::endl;
    outfile << objGift->xmlObject();
    outfile.close();
}

void PapaXmasConveyorBelt::OUT()
{
    if (!m_content) {
        std::cerr << "You pushed nothing to santa, what are you trying to do?" << std::endl;
        return;
    }
    generateXML(m_content);
    delete (m_content);
    m_content = nullptr;
}

IConveyorBelt *createConveyorBelt()
{
    return new PapaXmasConveyorBelt();
}