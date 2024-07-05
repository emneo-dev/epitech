/*
** EPITECH PROJECT, 2021
** Scene.hpp
** File description:
** Scene
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <functional>
#include <unordered_map>
#include "IScene.hpp"
#include "Entity.hpp"
#include "event/IEvent.hpp"
#include "event/KeyboardEvent.hpp"
#include "event/MouseEvent.hpp"
#include "Vector2.hpp"
#include "Vector.hpp"
#include <stack>
#include <list>

namespace arcade {
    class Scene : public IScene {
        public:
            Scene();
            ~Scene();

            void exit() override;
            void pushEvent(const event::IEvent& event) override;

            IEntity& newEntity(std::string name) override;
            IEntity& newEntity() override;
            std::vector<std::reference_wrapper<IEntity>> getEntity(const std::string& name) override;
            void removeEntity(const std::string& name) override;
            void removeEntity(const IEntity &entity) override;        

            void addScore(float score) override;
            void forEach(std::function<void(IEntity&)>) const override;
            void forEach(std::function<void(IEntity&)>, const std::string& name) override;
            void setWindowSize(int x, int y) override;
            math::Vector2 getWindowSize() const override;

            void forEachEvents(const std::function<void(const event::MouseEvent&)>& onMouseEvent,
                const std::function<void(const event::KeyboardEvent&)>& onKeyboardEvent);
            void clearEvents();
            bool running() const;

        protected:
        private:
            bool m_running;
            float m_score;
            math::Vec<std::size_t> m_windowPos;
            std::unordered_map<std::string, std::list<std::reference_wrapper<IEntity>>> m_entityList;
            std::vector<std::shared_ptr<event::IEvent>> m_eventStack;
    };
}

#endif /* !SCENE_HPP_ */