/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-pauline.faure
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include <stddef.h>
#include <memory>
#include "IGame.hpp"
#include "IScene.hpp"
#include "Entity.hpp"
#include "vector2.hpp"
#include "AGame.hpp"

namespace arcade {
    namespace lib {
        class Nibbler : public AGame {
            public:
                Nibbler();
                ~Nibbler();

                
                void init(IScene &) override;
                void update(IScene &, float) override;
                void end(IScene &) override;
                
                std::size_t getScore();
                std::size_t getHighScore();
                std::string getMap(std::string);
                math::Vector2 getPos();

                void updateSnakePos();
                std::size_t parseMap(std::string, size_t);
                void manageScore();
                void stockHighScore();
                void displayData();
                void displayMap();

            protected:
            private:
                std::vector<std::reference_wrapper<IEntity>> m_entity;
                std::vector<IScene> m_scene;
                std::vector<std::string> m_map;
                std::vector<math::Vector2> m_posFruits;
                std::vector<math::Vector2> m_snakeHead;
                std::size_t m_score;
                std::size_t m_life;
                std::size_t m_highScore;
                std::size_t m_time;
                std::size_t m_level;
                float m_x;
                float m_y;
        };
    }
}

#endif /* !NIBBLER_HPP_ */