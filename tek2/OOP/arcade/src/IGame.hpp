/*
** EPITECH PROJECT, 2021
** IGame.hpp
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include "ILibrary.hpp"
#include "event/MouseEvent.hpp"
#include "event/KeyboardEvent.hpp"

namespace arcade {

    namespace lib {

        class IGame : public ILibrary {
        public:
            virtual ~IGame() = default;

            /**
             * @brief Callback called for each keyboard event
             *
             * @param key event data
             */
            virtual void onKeyEvent(const event::KeyboardEvent& key) = 0;

            /**
             * @brief Callback called for each mouse event
             *
             * @param mouse event data
             */
            virtual void onMouseEvent(const event::MouseEvent& mouse) = 0;
        };

    }

}

#endif /* !IGAME_HPP_ */
