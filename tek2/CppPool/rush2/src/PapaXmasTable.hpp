/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPrush2-alexandre.descoins
** File description:
** PapaXmasTable
*/

#ifndef PAPAXMASTABLE_HPP_
#define PAPAXMASTABLE_HPP_

#include "ITable.hpp"

class PapaXmasTable : public ITable
{
public:
    PapaXmasTable();
    ~PapaXmasTable();
    Object *Take();
    Object *Take(int i);
    Object *Take(const std::string &type);
    bool Put(Object *);
    std::string* Look() const;

protected:
    Object *_content[10];
    std::string *_stringBuffer;

    void generateBuffer();
private:
};

ITable *createTable();

#endif /* !PAPAXMASTABLE_HPP_ */
