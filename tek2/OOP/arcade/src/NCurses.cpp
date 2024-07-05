//
// Created by huntears on 4/5/21.
//

#include <ncurses.h>
#include <iostream>
#include <unistd.h>
#include "NCurses.hpp"
#include "api.h"
#include "component/AsciiSprite.hpp"
#include "component/Transform.hpp"
#include "component/Text.hpp"

static const char *lib_name = "libNCurses";

static const char *lib_desc = "Graphics library made by Arcaac using NCurses";

extern "C" {

[[maybe_unused]]
void *library_create(void)
{
    auto *lib = new arcade::lib::NCurses();

    return lib;
}

[[maybe_unused]]
void library_delete(void *library)
{
    delete (arcade::lib::NCurses *)library;
}

[[maybe_unused]]
library_info_t library_get_data(void)
{
    library_info_t info;

    info.desc = lib_desc;
    info.date = time(nullptr);
    info.name = lib_name;
    info.type = library_info::GRAPHIC;
    return info;
}

}

namespace arcade {
    namespace lib {

        NCurses::NCurses() : m_maxFPS(5) {
            this->m_quit = false;
        }

        void NCurses::init(IScene &scene) {
            (void)scene;
            WINDOW *w = initscr();
            noecho();
            raw();
            cbreak();
            curs_set(0);
            nodelay(w, TRUE);
            keypad(w, TRUE);
        }

        void NCurses::update(IScene &scene, float dt) {
            if (dt < 1. / static_cast<float>(m_maxFPS)) {
                usleep(static_cast<unsigned long>(((1. / static_cast<float>(m_maxFPS)) - dt) * 1000000.));
            }
            handleEvents(scene);
            displaySprites(scene);
        }

        void NCurses::end(IScene &scene) {
            (void)scene;
            endwin();
        }

        bool NCurses::quitRequested() const {
            return m_quit;
        }

        void NCurses::handleEvents(IScene &scene) {
            int c = 0;
            while ((c = getch()) != ERR) {
                if (this->m_keyTable.find(c) != this->m_keyTable.end()) {
                    event::KeyboardEvent evt;
                    evt.key = this->m_keyTable.at(c);
                    evt.action = event::KeyboardEvent::DOWN;
                    scene.pushEvent(evt);
                }
            }
        }

        // I hate this
        void NCurses::displaySprites(IScene &scene) {
            clear();
            scene.forEach([&](IEntity &entity) {
                entity.forEach([&](component::IComponent &component) {
                    if (auto *aspr = dynamic_cast<component::AsciiSprite *>(&component)) {
                        component::Transform pos;
                        entity.forEach([&](component::IComponent &cpt) {
                            if (auto *tmpPos = dynamic_cast<component::Transform *>(&cpt)) {
                                pos = *tmpPos;
                            }
                        });
                        for (std::size_t i = 0; i < aspr->height; i++) {
                            for (std::size_t j = 0; j < aspr->width; j++) {
                                mvprintw(i + static_cast<int>(pos.position.y),
                                         j + static_cast<int>(pos.position.x),
                                         "%c",
                                         aspr->sprite->at(j + i * aspr->width));
                            }
                        }
                    }
                    else if (auto *aspr = dynamic_cast<component::Text *>(&component)) {
                        component::Transform pos;
                        entity.forEach([&](component::IComponent &cpt) {
                            if (auto *tmpPos = dynamic_cast<component::Transform *>(&cpt)) {
                                pos = *tmpPos;
                            }
                        });
                        mvprintw(pos.position.y, pos.position.x, "%s", aspr->text.data());
                    }
                });
            });
        }
    }
}