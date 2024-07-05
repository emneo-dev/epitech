//
// Created by huntears on 4/10/21.
//

#ifndef ARCADE_AGAME_HPP
#define ARCADE_AGAME_HPP

#include <stack>
#include "event/KeyboardEvent.hpp"
#include "event/MouseEvent.hpp"
#include "IGame.hpp"

namespace arcade {
    namespace lib {
        class AGame : public IGame {
        public:
            void onKeyEvent(const event::KeyboardEvent& key) override;
            void onMouseEvent(const event::MouseEvent& mouse) override;
            std::stack<event::MouseEvent> m_mouseEventStack;
            std::stack<event::KeyboardEvent> m_keyEventStack;

        private:
        };
    }
}

#endif //ARCADE_AGAME_HPP
