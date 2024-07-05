/*
** EPITECH PROJECT, 2021
** Day07A
** File description:
** Skat
*/

#ifndef SKAT_HPP_
#define SKAT_HPP_

#include <iostream>

class Skat {
public:
    Skat(const std::string &name = "bob", int stimPaks = 15);
    ~Skat();

    int &stimPaks();
    const std::string &name();

    void shareStimPaks(int number, int &stock);
    void addStimPaks(unsigned int number);
    void useStimPaks();
    void status() const;
protected:
private:
    std::string _name;
    int _myStock;
};

#endif /* !SKAT_HPP_ */
