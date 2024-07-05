/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-pauline.faure
** File description:
** Nibbler
*/

#include <iostream>
#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iterator>
#include "api.h"
#include "Nibbler.hpp"
#include "Scene.hpp"
#include "component/Sprite.hpp"
#include "component/IComponent.hpp"

static const char *lib_name = "libNibbler";

static const char *lib_desc = "Game library which corresponds to the Nibbler";

extern "C" {

    void *library_create(void)
    {
        auto *lib = new arcade::lib::Nibbler();

        return lib;
    }

    void library_delete(void *library)
    {
        delete (arcade::lib::Nibbler *)library;
    }

    library_info_t library_get_data(void)
    {
        library_info_t info;

        info.desc = lib_desc;
        info.date = time(nullptr);
        info.name = lib_name;
        info.type = library_info::GAME;
        return info;
    }
}

namespace arcade {
    namespace lib {
        Nibbler::Nibbler()
        {
            this->m_score = 0;
            this->m_life = 3;
            this->m_time = 0;
            this->m_highScore = getHighScore();
            this->m_level = 1;
            this->m_x = 0;
            this->m_y = 0;
        }

        Nibbler::~Nibbler()
        {
        }

        void Nibbler::init(IScene &scene)
        {
            component::Sprite sprite;
            (void)scene;
            // this->m_entity.push_back(scene.newEntity("player"));
            // this->m_entity.at(0).get().addComponent(sprite);
            // this->m_entity.at(0).get().forEach([&](component::IComponent &comp)
            // {
            // });
            // this->m_entity.push_back(scene.newEntity("fruit"));
            // this->m_entity.at(1).get().addComponent(sprite);
            // this->m_entity.at(0).get().forEach([&](component::IComponent &comp)
            // {

            // });

            getMap("../src/maps/Nibbler1.txt");
            getPos();
        }

        void Nibbler::update(IScene &scene, float dt)
        {
            (void)scene;
            (void)dt;
            std::string line = m_map.at(m_snakeHead.at(0).x);
            
            std::cout << "Update Nibbler" << std::endl;

            displayData();
            displayMap();
            while(this->m_keyEventStack.size() != 0) {
                event::KeyboardEvent evt = this->m_keyEventStack.top();
                this->m_keyEventStack.pop();
                if (evt.key == event::Key::KEY_ARROW_RIGHT)
                {
                    if (line[m_snakeHead.at(0).y + 1] == 'X')
                        break;
                    else
                        m_snakeHead.at(0).y += 1;
                }
                else if (evt.key == event::Key::KEY_ARROW_LEFT)
                {
                    if (line[m_snakeHead.at(0).y - 1] == 'X')
                        break;
                    else
                        m_snakeHead.at(0).y -= 1;
                }
                else if (evt.key == event::Key::KEY_ARROW_DOWN)
                {
                    line = m_map.at(m_snakeHead.at(0).x + 1);
                    if (line[m_snakeHead.at(0).y] == 'X')
                        break;
                    else
                        m_snakeHead.at(0).x += 1;
                }
                else if (evt.key == event::Key::KEY_ARROW_UP)
                {
                    line = m_map.at(m_snakeHead.at(0).x - 1);
                    if (line[m_snakeHead.at(0).y] == 'X')
                        break;
                    else
                        m_snakeHead.at(0).x -= 1;
                }
                updateSnakePos();
                manageScore();
            }
        }

        void Nibbler::updateSnakePos()
        {
            std::string line = m_map.at(m_snakeHead.at(0).x);
            if (line[m_snakeHead.at(0).y] == 'X')
            line[m_snakeHead.at(0).y] = 'O';
            m_map.at(m_snakeHead.at(0).x) = line;
        }

        void Nibbler::end(IScene &scene)
        {
            (void)scene;
            std::cout << "End of Nibbler" << std::endl;
        }

        size_t Nibbler::getScore()
        {
            return (this->m_score);
        }

        size_t Nibbler::getHighScore()
        {
            std::string line;

            if (this->m_score > this->m_highScore) {
                this->m_highScore = this->m_score;
                stockHighScore();
                std::cout << "New high score !" << std::endl;
            } else {
                std::ifstream file("../src/scores/Nibbler.txt");
                getline(file, line);
                m_highScore = std::stoi(line);
            }
            return (this->m_highScore);
        }

        std::string Nibbler::getMap(std::string filename)
        {
            std::size_t i = 0;
            std::size_t j = 0;
            std::string line;

            std::ifstream file(filename.c_str());
            while (std::getline(file, line)) {
                this->m_map.push_back(line);
                j = parseMap(m_map.at(i), j);
                i++;
            }
            return (line);
        }

        math::Vector2 Nibbler::getPos()
        {
            math::Vector2 x = {m_x,m_y};
            return (x);
        }

        void Nibbler::displayMap()
        {
            std::copy(this->m_map.begin(), this->m_map.end(),
                std::ostream_iterator<std::string>(std::cout, "\n"));
        }

        void Nibbler::displayData()
        {
            std::cout << "Player1\t\t" << this->m_score << "\t\tLEFT  " <<
            this->m_life << std::endl;
            std::cout << "HISCORE\t\t" << this->m_highScore << "\t\tTIME  " <<
            this->m_time << std::endl << std::endl;
        }

        std::size_t Nibbler::parseMap(std::string line, std::size_t j)
        {
            std::size_t pos_y = 0;
            static std::size_t count = 0;
            std::size_t i = 0;

            for (; line[i] != '\0'; i++) {
                if (line[i] == '*') {
                    this->m_x = count;
                    this->m_y = pos_y;
                    this->m_posFruits.push_back(getPos());
                    j++;
                }
                if (line[i] == 'O') {
                    this->m_x = count;
                    this->m_y = pos_y;
                    this->m_snakeHead.push_back(getPos());
                }
                pos_y++;
            }
            count++;
            return (j);
        }

        void Nibbler::manageScore()
        {
            for (size_t i = 0; i < this->m_posFruits.size(); i++) {
                if (this->m_posFruits.at(i).x == this->m_snakeHead.at(0).x &&
                    this->m_posFruits.at(i).y == this->m_snakeHead.at(0).y) {
                    this->m_score += 10;
                    // serpent + 1 'o'
                    //supprimer le fruit
                    return;
                    }
            }
        }

        void Nibbler::stockHighScore()
        {
            std::fstream fs; 
            fs.open("../src/scores/Nibbler.txt", std::fstream::out);
            if (fs.is_open()) {
                fs << m_highScore;
            }
            fs.close();
        }
    }
}