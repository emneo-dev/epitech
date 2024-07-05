/*
** EPITECH PROJECT, 2021
** Day08
** File description:
** DroidMemory
*/

#ifndef DROIDMEMORY_HPP_
#define DROIDMEMORY_HPP_

#include <cstddef>

class DroidMemory {
public:
    DroidMemory();
    ~DroidMemory();

    size_t getExp() const;
    size_t getFingerprint() const;
    void setExp(size_t value);
    void setFingerprint(size_t value);

    DroidMemory &operator<<(const DroidMemory &memory);
    DroidMemory &operator>>(DroidMemory &memory) const;
    DroidMemory &operator+=(const DroidMemory &memory);
    DroidMemory &operator+=(const size_t &experience);
    DroidMemory operator+(const DroidMemory &memory) const;
    DroidMemory operator+(const size_t &experience) const;

protected:
private:
    size_t Fingerprint;
    size_t Exp;
};

std::ostream &operator<<(std::ostream &os, const DroidMemory &memory);

#endif /* !DROIDMEMORY_HPP_ */
