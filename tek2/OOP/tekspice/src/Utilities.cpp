/*
** EPITECH PROJECT, 2021
** nano
** File description:
** Utilities
*/

#include "IComponent.hpp"

namespace nts {
    std::string getStringFromTristate(nts::Tristate state) {
        switch (state) {
        case nts::Tristate::FALSE:
            return "0";
        case nts::Tristate::TRUE:
            return "1";
        default:
            return "U";
        }
    }
}