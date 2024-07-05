/*
** EPITECH PROJECT, 2021
** IComponent.hpp
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <string>

namespace arcade {

    namespace component {

        enum class ComponentType { SPRITE, TEXT, ASCII_SPRITE, SOUND, OTHER };

        class IComponent {
        public:
            virtual ~IComponent() = default;

        protected:
        private:
        };

    }

}

#endif /* !ICOMPONENT_HPP_ */
