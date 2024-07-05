/*
** EPITECH PROJECT, 2021
** Entity.cpp
** File description:
** Entity
*/

#include <iostream>
#include "Entity.hpp"
#include "component/Transform.hpp"

namespace arcade {

    Entity::Entity(const std::string &name)
    {
        this->m_name = name;
        this->m_pos = {0, 0, 0};
    }

    // Every person who thought passing a constant reference was a good idea can fuck off
    // This is gonna copy whole ass sprites, and I hate this with a deep passion
    void Entity::addComponent(const component::IComponent& component)
    {
        if (auto *ptr = dynamic_cast<const component::AsciiSprite *>(&component))
            this->m_components.emplace_back(std::make_shared<component::AsciiSprite>(*ptr));
        else if (auto *ptr = dynamic_cast<const component::Sprite *>(&component))
            this->m_components.emplace_back(std::make_shared<component::Sprite>(*ptr));
        else if (auto *ptr = dynamic_cast<const component::Text *>(&component))
            this->m_components.emplace_back(std::make_shared<component::Text>(*ptr));
        else if (auto *ptr = dynamic_cast<const component::Transform *>(&component))
            this->m_components.emplace_back(std::make_shared<component::Transform>(*ptr));
    }

    void Entity::removeComponent(const component::IComponent& component)
    {
        if (dynamic_cast<const component::AsciiSprite *>(&component)) {
            for (auto it = this->m_components.begin(); it != this->m_components.end(); it++)
                if (dynamic_cast<component::AsciiSprite *>(it->get())) {
                    this->m_components.erase(it);
                    return;
                }
        }
        else if (dynamic_cast<const component::Sprite *>(&component)) {
            for (auto it = this->m_components.begin(); it != this->m_components.end(); it++)
                if (dynamic_cast<component::Sprite *>(it->get())) {
                    this->m_components.erase(it);
                    return;
                }
        }
        else if (dynamic_cast<const component::Text *>(&component)) {
            for (auto it = this->m_components.begin(); it != this->m_components.end(); it++)
                if (dynamic_cast<component::Text *>(it->get())) {
                    this->m_components.erase(it);
                    return;
                }
        }
        else if (dynamic_cast<const component::Transform *>(&component)) {
            for (auto it = this->m_components.begin(); it != this->m_components.end(); it++)
                if (dynamic_cast<component::Transform *>(it->get())) {
                    this->m_components.erase(it);
                    return;
                }
        }
    }

    void Entity::forEach(std::function<void(component::IComponent&)> fun) const
    {
        for (auto& component : this->m_components)
            fun(*component);
    }

    const std::string &Entity::getName() const
    {
        return this->m_name;
    }

    const math::Vector3 &Entity::getPos() const 
    {
        return this->m_pos;
    }

    void Entity::setPos(const math::Vector3 &pos) 
    {
       this->m_pos = pos;
    }
}