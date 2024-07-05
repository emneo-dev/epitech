//
// Created by huntears on 4/10/21.
//

#ifndef ARCADE_MAINMENU_HPP
#define ARCADE_MAINMENU_HPP

#include <memory>
#include <stack>
#include "LibraryHandler.hpp"
#include "event/KeyboardEvent.hpp"
#include "event/MouseEvent.hpp"
#include "component/Transform.hpp"
#include "Scene.hpp"

namespace arcade {
    class MainMenu {
    public:
        MainMenu(std::unique_ptr<lib::LibHandler> graphicHandler);
        void run();
        void onKeyEvent(const event::KeyboardEvent& key);
        void onMouseEvent(const event::MouseEvent& mouse);
    private:
        std::unique_ptr<lib::LibHandler> m_graphicHandler;
        Scene m_scene;
        bool m_requestQuit;
        std::stack<event::KeyboardEvent> m_keyEventStack;
        std::stack<event::MouseEvent> m_mouseEventStack;
        std::vector<std::unique_ptr<lib::LibHandler>> m_graphicLibs;
        std::vector<std::unique_ptr<lib::LibHandler>> m_gameLibs;
    };

}


#endif //ARCADE_MAINMENU_HPP
