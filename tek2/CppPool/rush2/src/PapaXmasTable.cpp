/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPrush2-alexandre.descoins
** File description:
** PapaXmasTable
*/

#include "PapaXmasTable.hpp"

PapaXmasTable::PapaXmasTable()
{
    for (int i = 0; i < 10; i++)
        this->_content[i] = nullptr;
    this->_stringBuffer = new std::string[10];
    this->generateBuffer();
}

PapaXmasTable::~PapaXmasTable()
{
    delete this->_stringBuffer;
    for (int i = 0; i < 10; i++)
        delete this->_content[i];
}

void PapaXmasTable::generateBuffer()
{
    for (int i = 0; i < 10; i++) {
        if (this->_content[i])
            this->_stringBuffer[i] = this->_content[i]->getTypeName();
        else
            this->_stringBuffer[i] = "unknown";
    }
}

std::string *PapaXmasTable::Look() const
{
    return this->_stringBuffer;
}

Object *PapaXmasTable::Take(const std::string &type)
{
    for (int i = 0; i < 10; i++)
        if (this->_content[i] && this->_content[i]->getTypeName() == type)
            return this->Take(i);
    std::cerr << "There is no object of this type on the table!" << std::endl;
    return nullptr;
}

Object *PapaXmasTable::Take(int i)
{
    if (i >= 10 || i < 0 || !this->_content[i]) {
        std::cerr << "The requested object does not exist !" << std::endl;
        return nullptr;
    }
    this->_content[i]->isTaken();
    Object *toReturn = this->_content[i];
    this->_content[i] = nullptr;
    this->generateBuffer();
    return toReturn;
}

Object *PapaXmasTable::Take()
{
    for (int i = 0; i < 10; i++)
        if (this->_content[i])
            return this->Take(i);
    std::cerr << "No object found, the table is empty !" << std::endl;
    return nullptr;
}

bool PapaXmasTable::Put(Object *obj) {
    for (int i = 0; i < 10; i++)
        if (!this->_content[i]) {
            this->_content[i] = obj;
            obj->setTaken(false);
            this->generateBuffer();
            return true;
        }
    std::cerr << "The table is full, it collapses !" << std::endl;
    delete this;
    return false;
}

ITable *createTable()
{
    return new PapaXmasTable();
}