//
// Created by huntears on 1/15/21.
//

#ifndef DAY10_VICTIM_HPP
#define DAY10_VICTIM_HPP

#include <iostream>

class Victim {
public:
    Victim(const std::string &name);
    ~Victim();
    virtual void getPolymorphed() const;
private:
public:
    const std::string &getName() const;

protected:
    const std::string _name;

};

std::ostream &operator<<(std::ostream &os, const Victim &victim);

#endif //DAY10_VICTIM_HPP
