/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPrush2-alexandre.descoins
** File description:
** Elf
*/

#include "Wrap.hpp"
#include "Elf.hpp"

Elf::Elf()
{
}

Elf::~Elf()
{
}

void Elf::setConveyor(IConveyorBelt *belt)
{
    m_conveyor = belt;
}

void Elf::setTable(ITable *table)
{
    m_table = table;
}

bool Elf::CheckMaterialGift() const
{
    std::string *table_content = m_table->Look();
    bool has_toy = 0;
    bool has_box = 0;
    bool has_paper = 0;
    
    for (int i = 0; i < 10; i++) {
        if (table_content[i] == "toy")
            has_toy = true;
        else if (table_content[i] == "box")
            has_box = true;
        else if (table_content[i] == "paper")
            has_paper = true;
    }
    return (has_toy && has_box && has_paper);
}

void Elf::WrapGift()
{
    Object *toy = m_table->Take("toy");
    Object *box = m_table->Take("box");
    Object *paper;

    box->openMe();
    box->wrapMeThat(toy);
    box->closeMe();
    paper = m_table->Take("paper");
    paper->wrapMeThat(box);
    m_gift = paper;
}

bool Elf::CheckToy()
{
    std::string *table_content = m_table->Look();

    for (int i = 0; i < 10; i++) {
        if (table_content[i] == "toy")
            return (true);
    }
    return (false);
}

bool Elf::CheckTable() const
{
    std::string *table_content = m_table->Look();

    for (int i = 0; i < 10; i++) {
        if (table_content[i] == "unknown")
            return (true);
    }
    return (false);
}

void Elf::WorkLoop()
{
    while (CheckMaterialGift() || (CheckToy() && CheckTable())) {
        if (CheckMaterialGift()) {
            WrapGift();
            m_conveyor->Put(m_gift);
            m_conveyor->OUT();
            m_gift = nullptr;
        } else {
            AskWrap();
        }
    }
    std::cout << "o'pa ere's somin' wron' in da box!" << std::endl;
}

void Elf::AskWrap()
{
    Object *generated;

    m_conveyor->IN();
    generated = m_conveyor->Take();
    m_table->Put(generated);
}
