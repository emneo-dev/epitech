/*
** EPITECH PROJECT, 2021
** Day08
** File description:
** Droid
*/

#ifndef DROID_HPP_
#define DROID_HPP_

#include <string>
#include <iostream>

#include "DroidMemory.hpp"

class Droid {
private:
    std::string *_status = nullptr;
    size_t _energy = 50;
    std::string _id;
    const size_t _attack = 25;
    const size_t _toughness = 25;
    DroidMemory *BattleData = nullptr;

public:
    Droid();
    Droid(std::string serial);
    Droid(const Droid &other);
    ~Droid();

    const std::string &getId() const;
    size_t getEnergy() const;
    size_t getAttack() const;
    size_t getToughness() const;
    std::string *getStatus() const;
    DroidMemory *getBattleData() const;

    void setId(const std::string &id);
    void setEnergy(size_t energy);
    void setStatus(std::string *status);
    void setBattleData() const;

    Droid &operator=(const Droid &other);
    bool operator!=(const Droid &rhs) const;
    bool operator==(const Droid &rhs) const;
    Droid &operator<<(size_t &energy);
};

std::ostream &operator<<(std::ostream &os, const Droid &droid);

#endif /* DROID_HPP_ */
