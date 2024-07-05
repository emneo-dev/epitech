/*
** EPITECH PROJECT, 2021
** Entity.hpp
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <vector>
#include <list>
#include <functional>
#include "IEntity.hpp"
#include "component/Sprite.hpp"
#include "component/Text.hpp"
#include "component/AsciiSprite.hpp"

namespace arcade {
    class Entity : public IEntity {
        public:
            explicit Entity(const std::string &name = std::string());
            ~Entity() override = default;

            // add component to entity
            void addComponent(const component::IComponent& component) override;
            // remove component from entity
            void removeComponent(const component::IComponent& component) override;

            // for each components from entity, execute fun
            void forEach(std::function<void(component::IComponent&)> fun) const override;
    
            const std::string &getName() const;

            const math::Vector3 &getPos() const;

            void setPos(const math::Vector3 &pos);
        protected:
        private:
            std::string m_name;
            math::Vector3 m_pos;
            std::list<std::shared_ptr<component::IComponent>> m_components;
    };
}

#endif /* !ENTITY_HPP_ */