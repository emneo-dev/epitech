/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPrush2-alexandre.descoins
** File description:
** Elf
*/

#ifndef ELF_HPP_
#define ELF_HPP_

#include "IElf.hpp"
#include "ITable.hpp"
#include "IConveyorBelt.hpp"

class Elf : public IElf
{
    public:
        Elf();
        ~Elf();
        void WorkLoop();
        void setConveyor(IConveyorBelt *belt);
        void setTable(ITable *talbe);
    protected:
        bool CheckMaterialGift() const;
        bool CheckTable() const;
        void WrapGift();
        void AskWrap();
        bool CheckToy();

        Object *m_gift;
        ITable *m_table;
        IConveyorBelt *m_conveyor;
};

#endif /* !ELF_HPP_ */