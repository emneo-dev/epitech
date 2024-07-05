/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPrush2-alexandre.descoins
** File description:
** IElf
*/

#ifndef IELF_HPP_
#define IELF_HPP_

#include "Object.hpp"

class IElf {
    public:
        virtual void WorkLoop() = 0;
    protected:
        virtual ~IElf() {}
        virtual bool CheckMaterialGift() const = 0;
        virtual bool CheckTable() const = 0;
        virtual void WrapGift() = 0;
        virtual void AskWrap() = 0;
};

#endif /* !IELF_HPP_ */