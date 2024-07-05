/*
** EPITECH PROJECT, 2021
** IGraphic.hpp
** File description:
** IGraphic
*/

#ifndef IGRAPHIC_HPP_
#define IGRAPHIC_HPP_

#include "ILibrary.hpp"

namespace arcade {

    namespace lib {

        class IGraphic : public ILibrary {
            public:
                virtual ~IGraphic() = default;

                /**
                 * @brief Check if the user has requested to quit the game
                 */
                virtual bool quitRequested() const = 0;

            protected:
            private:
        };

    }

}

#endif /* !IGRAPHIC_HPP_ */
