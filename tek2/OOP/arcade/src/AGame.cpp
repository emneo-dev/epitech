//
// Created by huntears on 4/10/21.
//

#include "AGame.hpp"

namespace arcade {
    namespace lib {

        void AGame::onKeyEvent(const event::KeyboardEvent &key) {
            m_keyEventStack.push(key);
        }

        void AGame::onMouseEvent(const event::MouseEvent &mouse) {
            m_mouseEventStack.push(mouse);
        }
    }
}