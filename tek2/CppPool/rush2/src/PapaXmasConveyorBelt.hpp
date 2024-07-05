/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPrush2-alexandre.descoins
** File description:
** PapaXmasConveyorBelt
*/

#ifndef PAPAXMASCONVEYORBELT_HPP_
#define PAPAXMASCONVEYORBELT_HPP_

#include "IConveyorBelt.hpp"

class PapaXmasConveyorBelt : public IConveyorBelt
{
public:
    PapaXmasConveyorBelt();
    ~PapaXmasConveyorBelt();

    Object *Take();
    bool Put(Object *);
    void IN();
    void OUT();
    std::string Look() const;
    void generateXML(Object *);
protected:
    Object *m_content;
    std::string m_name;
    int nbrGift;
private:
};

IConveyorBelt *createConveyorBelt();

#endif /* !PAPAXMASCONVEYORBELT_HPP_ */
