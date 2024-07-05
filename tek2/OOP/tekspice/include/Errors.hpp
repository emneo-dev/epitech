//
// Created by huntears on 03/03/2021.
//

#ifndef NANOTEKSPICE_ERRORS_HPP
#define NANOTEKSPICE_ERRORS_HPP

#include <exception>

namespace nts {
    class ComponentTypeUnknown: public std::exception
    {
        const char* what() const noexcept override
        {
            return "My exception happened";
        }
    };

    class ComponentNameUnknown: public std::exception
    {
        const char* what() const noexcept override
        {
            return "My exception happened";
        }
    };

    class PinNumberUnknown: public std::exception
    {
        const char* what() const noexcept override
        {
            return "The pin number is unknown";
        }
    };

    class AlreadyExistingName: public std::exception
    {
        const char* what() const noexcept override
        {
            return "A component with that name already exists";
        }
    };

    class NoChipsetInCircuit: public std::exception
    {
        const char* what() const noexcept override
        {
            return "There are no chipsets in the circuit";
        }
    };

    class SyntaxError: public std::exception
    {
        const char* what() const noexcept override
        {
            return "A syntax error is present in the file";
        }
    };
}

#endif //NANOTEKSPICE_ERRORS_HPP
