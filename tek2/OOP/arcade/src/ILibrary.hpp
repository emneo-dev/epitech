/*
** EPITECH PROJECT, 2021
** ILibrary.hpp
** File description:
** ILibrary
*/

#ifndef ILIBRARY_HPP_
#define ILIBRARY_HPP_

#include "IScene.hpp"

namespace arcade {

    namespace lib {

        class ILibrary {
            public:
                virtual ~ILibrary() = default;

                /**
                 * @brief Initialise the library
                 *
                 * @param scene
                 */
                virtual void init(IScene &scene) = 0;

                /**
                 * @brief Update the library logic
                 *
                 * @param scene
                 * @param dt Time elapsed since the last update (in seconds)
                 */
                virtual void update(IScene &scene, float dt) = 0;

                /**
                 * @brief Cleanup all resources associated with this library instance
                 *
                 * @param scene
                 */
                virtual void end(IScene &scene) = 0;
        };

    }

}

#endif /* !ILIBRARY_HPP_ */
