/*
** EPITECH PROJECT, 2021
** Day07M
** File description:
** WarpSystem
*/

#include "WarpSystem.hpp"

namespace WarpSystem
{
    QuantumReactor::QuantumReactor()
    {
        this->_stability = true;
    }

    bool QuantumReactor::isStable()
    {
        return this->_stability;
    }

    void QuantumReactor::setStability(bool stability)
    {
        this->_stability = stability;
    }

    Core::Core(QuantumReactor *core)
    {
        this->_coreReactor = core;
    }

    QuantumReactor *Core::checkReactor()
    {
        return this->_coreReactor;
    }
}