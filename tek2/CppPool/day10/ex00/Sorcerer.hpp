//
// Created by huntears on 1/15/21.
//

#ifndef DAY10_SORCERER_HPP
#define DAY10_SORCERER_HPP

#include <iostream>
#include "Victim.hpp"

class Sorcerer {
public:
    Sorcerer(const std::string &name, const std::string &title);
    ~Sorcerer();

private:
    const std::string _name;
    const std::string _title;
public:
    const std::string &getName() const;
    const std::string &getTitle() const;
    void polymorph(const Victim &victim) const;
};

std::ostream &operator <<(std::ostream &os, const Sorcerer &obj);

#endif //DAY10_SORCERER_HPP
