//
// Created by huntears on 4/5/21.
//

#ifndef ARCADE_NCURSES_HPP
#define ARCADE_NCURSES_HPP

#include <unordered_map>
#include "IGraphic.hpp"
#include "event/KeyboardEvent.hpp"

namespace arcade {
    namespace lib {
        class NCurses : public IGraphic {
        public:
            NCurses();
            ~NCurses() override = default;

            void init(IScene &scene) override;
            void update(IScene &scene, float dt) override;
            void end(IScene &scene) override;
            bool quitRequested() const override;

        protected:
        private:
            void handleEvents(IScene &scene);
            void displaySprites(IScene &scene);
            bool m_quit;
            const std::size_t m_maxFPS;
            const std::unordered_map<int, event::Key> m_keyTable = {
                    {97,  event::Key::KEY_A},
                    {98,  event::Key::KEY_B},
                    {99,  event::Key::KEY_C},
                    {100, event::Key::KEY_D},
                    {101, event::Key::KEY_E},
                    {102, event::Key::KEY_F},
                    {103, event::Key::KEY_G},
                    {104, event::Key::KEY_H},
                    {105, event::Key::KEY_I},
                    {106, event::Key::KEY_J},
                    {107, event::Key::KEY_K},
                    {108, event::Key::KEY_L},
                    {109, event::Key::KEY_M},
                    {110, event::Key::KEY_N},
                    {111, event::Key::KEY_O},
                    {112, event::Key::KEY_P},
                    {113, event::Key::KEY_Q},
                    {114, event::Key::KEY_R},
                    {115, event::Key::KEY_S},
                    {116, event::Key::KEY_T},
                    {117, event::Key::KEY_U},
                    {118, event::Key::KEY_V},
                    {119, event::Key::KEY_W},
                    {120, event::Key::KEY_X},
                    {121, event::Key::KEY_Y},
                    {122, event::Key::KEY_Z},
                    {KEY_BACKSPACE, event::Key::KEY_BACK_SPACE},
                    {9, event::Key::KEY_TAB},
                    {27, event::Key::KEY_ESCAPE},
                    {330, event::Key::KEY_DELETE},
                    {KEY_UP, event::Key::KEY_ARROW_UP},
                    {KEY_DOWN, event::Key::KEY_ARROW_DOWN},
                    {KEY_LEFT, event::Key::KEY_ARROW_LEFT},
                    {KEY_RIGHT, event::Key::KEY_ARROW_RIGHT},
                    {331, event::Key::KEY_INSERT},
                    {48, event::Key::KEY_0},
                    {49, event::Key::KEY_1},
                    {50, event::Key::KEY_2},
                    {51, event::Key::KEY_3},
                    {52, event::Key::KEY_4},
                    {53, event::Key::KEY_5},
                    {54, event::Key::KEY_6},
                    {55, event::Key::KEY_7},
                    {56, event::Key::KEY_8},
                    {57, event::Key::KEY_9},
                    {KEY_F(1), event::Key::KEY_F1},
                    {KEY_F(2), event::Key::KEY_F2},
                    {KEY_F(3), event::Key::KEY_F3},
                    {KEY_F(4), event::Key::KEY_F4},
                    {KEY_F(5), event::Key::KEY_F5},
                    {KEY_F(6), event::Key::KEY_F6},
                    {KEY_F(7), event::Key::KEY_F7},
                    {KEY_F(8), event::Key::KEY_F8},
                    {KEY_F(9), event::Key::KEY_F9},
                    {KEY_F(10), event::Key::KEY_F10},
                    {KEY_F(11), event::Key::KEY_F11},
                    {KEY_F(12), event::Key::KEY_F12},
                    {KEY_END, event::Key::KEY_END_FILE},
                    {' ', event::Key::KEY_SPACE},
                    {KEY_PPAGE, event::Key::KEY_PAGE_UP},
                    {KEY_NPAGE, event::Key::KEY_PAGE_DOWN},
                    {KEY_SRIGHT, event::Key::KEY_SHIFT_RIGHT},
                    {KEY_SLEFT, event::Key::KEY_SHIFT_LEFT},
            };
        };
    }
}

#endif //ARCADE_NCURSES_HPP
