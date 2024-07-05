//
// Created by huntears on 1/17/21.
//

#ifndef DAY10_PEON_HPP
#define DAY10_PEON_HPP

#include "Victim.hpp"

class Peon : public Victim {
public:
    Peon(const std::string &name);
    ~Peon();
    void getPolymorphed() const;
};

#endif //DAY10_PEON_HPP
