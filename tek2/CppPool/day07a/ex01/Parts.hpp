/*
** EPITECH PROJECT, 2021
** Day07A [SSH: 192.168.0.19]
** File description:
** Parts
*/

#ifndef PARTS_HPP_
#define PARTS_HPP_

#include <iostream>

class Parts {
public:
    Parts(std::string const &serial = "P-01", bool functional = true);

    bool isFunctional() const;
    std::string serial() const;
    void informations() const;
    std::string _partType;
protected:
    std::string _serial;
    bool _functional;
private:
};

class Arms : public Parts{
public:
    Arms(std::string const &serial = "A-01", bool functional = true);
};

class Legs : public Parts{
public:
    Legs(std::string const &serial = "L-01", bool functional = true);
};

class Head : public Parts{
public:
    Head(std::string const &serial = "H-01", bool functional = true);
};

#endif /* !PARTS_HPP_ */
