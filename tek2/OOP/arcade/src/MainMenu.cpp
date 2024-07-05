//
// Created by huntears on 4/10/21.
//

#include <iostream>
#include <memory>
#include <vector>
#include <dirent.h>

#include "IGraphic.hpp"
#include "MainMenu.hpp"
#include "component/Transform.hpp"

namespace arcade {

    MainMenu::MainMenu(std::unique_ptr<lib::LibHandler> graphicHandler) :
        m_graphicHandler(std::move(graphicHandler)),
        m_scene(),
        m_requestQuit(false)
    {
        std::vector<std::unique_ptr<lib::LibHandler>> tmp;
        DIR *dr;
        struct dirent *en;
        dr = opendir("./lib/");
        if (!dr) {
            std::cerr << "Lib folder impossible to open !" << std::endl;
            exit(84);
        }
        while ((en = readdir(dr))) {
            try {
                tmp.emplace_back(std::make_unique<arcade::lib::LibHandler>(std::string(en->d_name)));
            }
            catch (const std::exception &e) {}
        }
        for (auto &i : tmp) {
            if (i->getInfo().type == library_info::GAME) {
                m_gameLibs.emplace_back(std::move(i));
            }
            else {
                m_graphicLibs.emplace_back(std::move(i));
            }
        }

        component::Transform trans;
        component::Text text;

        auto *ent = dynamic_cast<Entity *>(&m_scene.newEntity());
        if (ent == nullptr) {
            return;
        }
        trans.position = {0, 0, 0};
        ent->addComponent(trans);
        text.text = "Main menu - Arcaac";
        ent->addComponent(text);

        ent = dynamic_cast<Entity *>(&m_scene.newEntity());
        if (ent == nullptr) {
            return;
        }
        trans.position = {0, 3, 0};
        ent->addComponent(trans);
        text.text = "Available games :";
        ent->addComponent(text);

        ent = dynamic_cast<Entity *>(&m_scene.newEntity());
        if (ent == nullptr) {
            return;
        }
        trans.position = {0, static_cast<float>(5 + m_gameLibs.size()), 0};
        ent->addComponent(trans);
        text.text = "Available graphics :";
        ent->addComponent(text);

        for (std::size_t i = 0; i < m_gameLibs.size(); i++) {
            ent = dynamic_cast<Entity *>(&m_scene.newEntity());
            if (ent == nullptr) {
                return;
            }
            trans.position = {0, static_cast<float>(4 + i), 0};
            ent->addComponent(trans);
            text.text = "\t- " + std::string(m_gameLibs.at(i)->getInfo().name);
            ent->addComponent(text);
        }
        for (std::size_t i = 0; i < m_graphicLibs.size(); i++) {
            ent = dynamic_cast<Entity *>(&m_scene.newEntity());
            if (ent == nullptr) {
                return;
            }
            trans.position = {0, static_cast<float>(6 + m_gameLibs.size() + i), 0};
            ent->addComponent(trans);
            text.text = "\t- " + std::string(m_graphicLibs.at(i)->getInfo().name);
            ent->addComponent(text);
        }
    }

    void MainMenu::run() {
        m_graphicHandler->lib->init(m_scene);
        clock_t begin = clock();
        while (!this->m_requestQuit && !(dynamic_cast<arcade::lib::IGraphic *>(m_graphicHandler->lib))->quitRequested()) {
            m_graphicHandler->lib->update(m_scene, static_cast<float>(clock() - begin) / CLOCKS_PER_SEC);
            m_scene.forEachEvents([&](const event::MouseEvent &key) {
                    this->onMouseEvent(key);
                }, [&](const event::KeyboardEvent &key) {
                    this->onKeyEvent(key);
                });
            m_scene.clearEvents();
        }
        m_graphicHandler->lib->end(m_scene);
    }

    void MainMenu::onKeyEvent(const event::KeyboardEvent &key) {
        if (key.action == event::KeyboardEvent::DOWN && key.key == event::Key::KEY_ESCAPE)
            this->m_requestQuit = true;
    }

    // Who needs a mouse ?
    void MainMenu::onMouseEvent(const event::MouseEvent &mouse) {
        (void)mouse;
    }

    //std::unique_ptr<arcade::lib::LibHandler> lib2 = std::make_unique<arcade::lib::LibHandler>(std::string(av[2]));

    //arcade::Scene ree;
    //lib2->lib->init(ree);

    //lib->lib->init(ree);
    //while (!(dynamic_cast<arcade::lib::IGraphic *>(lib->lib))->quitRequested() && ree.running()) {
    //    lib->lib->update(ree, 0.1);
    //    ree.forEachEvents([&](const arcade::event::MouseEvent &key) {
    //        (dynamic_cast<arcade::lib::IGame *>(lib2->lib))->onMouseEvent(key);
    //    }, [&](const arcade::event::KeyboardEvent &key) {
    //        (dynamic_cast<arcade::lib::IGame *>(lib2->lib))->onKeyEvent(key);
    //    });
    //    lib2->lib->update(ree, 0.1);
    //    ree.clearEvents();
    //}
    //lib2->lib->end(ree);

    //lib->lib->end(ree);
}