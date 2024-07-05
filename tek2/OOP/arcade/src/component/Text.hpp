/*
** EPITECH PROJECT, 2021
** Text.hpp
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include "IComponent.hpp"
#include <string>

namespace arcade {

    namespace component {

        struct Text : public IComponent {
            std::string text;
        };

    }

}

#endif /* !TEXT_HPP_ */
