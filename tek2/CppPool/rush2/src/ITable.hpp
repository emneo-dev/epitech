/*
** EPITECH PROJECT, 2021
** B-CPP-300-TLS-3-1-CPPrush2-alexandre.descoins
** File description:
** ITable
*/

#ifndef ITABLE_HPP_
#define ITABLE_HPP_

#include "Object.hpp"

class ITable
{
public:
    virtual ~ITable() {}
    virtual Object *Take() = 0;
    virtual Object *Take(int i) = 0;
    virtual Object *Take(const std::string &type) = 0;
    virtual bool Put(Object *) = 0;
    virtual std::string* Look() const = 0;
};

#endif /* !ITABLE_HPP_ */
