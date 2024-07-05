/*
** EPITECH PROJECT, 2021
** Scene.cpp
** File description:
** Scene
*/

#include <iostream>
#include "Scene.hpp"
#include "event/KeyboardEvent.hpp"
#include "event/MouseEvent.hpp"

namespace arcade {

    Scene::Scene() : m_score(0), m_windowPos({0, 0})
    {
        m_running = true;
    }

    Scene::~Scene()
    {
        for (auto &it : this->m_entityList) {
            for (auto &jaaj : it.second) {
                delete &jaaj.get();
            }
        }
    }

    void Scene::exit()
    {
        this->m_running = false;
    }

    void Scene::pushEvent(const event::IEvent& event)
    {
        if (auto *ptr = dynamic_cast<const event::KeyboardEvent *>(&event))
            this->m_eventStack.emplace_back(std::make_shared<event::KeyboardEvent>(*ptr));
        else if (auto *ptr = dynamic_cast<const event::MouseEvent *>(&event))
            this->m_eventStack.emplace_back(std::make_shared<event::MouseEvent>(*ptr));
    }

    IEntity& Scene::newEntity(std::string name)
    {
        auto newEntity = new Entity(name);

        if (this->m_entityList.find(name) == this->m_entityList.end())
            this->m_entityList[name] = std::list<std::reference_wrapper<IEntity>>({*newEntity});
        else
            this->m_entityList[name].emplace_back(*newEntity);
        return *newEntity;
    }

    IEntity& Scene::newEntity()
    {
        auto newEntity = new Entity();
        const std::string name;

        if (this->m_entityList.find(name) == this->m_entityList.end())
            this->m_entityList[name] = std::list<std::reference_wrapper<IEntity>>({*newEntity});
        else
            this->m_entityList[name].emplace_back(*newEntity);
        return *newEntity;
    }

    std::vector<std::reference_wrapper<IEntity>> Scene::getEntity(const std::string& name)
    {
        if (this->m_entityList.find(name) != this->m_entityList.end()) {
            return std::vector<std::reference_wrapper<IEntity>>(this->m_entityList[name].begin(),
                    this->m_entityList[name].end());
        }
        return std::vector<std::reference_wrapper<IEntity>>();
    }

    void Scene::removeEntity(const std::string& name)
    {
        this->m_entityList.erase(name);
    }

    void Scene::removeEntity(const IEntity &entity)
    {
        for (auto& entities : this->m_entityList) {
            for (auto it = entities.second.begin(); it != entities.second.end(); it++) {
                if (&it->get() == &entity) {
                    entities.second.erase(it);
                    return;
                }
            }
        }
    }

    void Scene::addScore(float score)
    {
        this->m_score += score;
    }

    void Scene::forEach(std::function<void(IEntity&)> fun) const
    {
        for (const auto& entities : this->m_entityList)
            for (auto& entity : entities.second)
                fun(entity);
    }

    void Scene::forEach(std::function<void(IEntity&)> fun, const std::string& name)
    {
        if (this->m_entityList.find(name) == this->m_entityList.end())
            return;
        const auto& entities = this->m_entityList[name];
        for (auto& entity : entities)
            fun(entity);
    }

    void Scene::setWindowSize(int x, int y)
    {
        this->m_windowPos.data[0] = x;
        this->m_windowPos.data[1] = y;
    }

    math::Vector2 Scene::getWindowSize() const
    {
        return math::Vector2({static_cast<float>(this->m_windowPos.data[0]),
                              static_cast<float>(this->m_windowPos.data[1])});
    }

    void Scene::forEachEvents(const std::function<void(const event::MouseEvent&)>& onMouseEvent,
                const std::function<void(const event::KeyboardEvent&)>& onKeyboardEvent)
    {
        for (auto &evt : this->m_eventStack) {
            if (auto *kevt = dynamic_cast<event::KeyboardEvent *>(evt.get())) {
                onKeyboardEvent(*kevt);
            }
            else if (auto *mevt = dynamic_cast<event::MouseEvent *>(evt.get())) {
                onMouseEvent(*mevt);
            }
        }
    }

    void Scene::clearEvents()
    {
        this->m_eventStack.clear();
    }

    bool Scene::running() const {
        return m_running;
    }

}