/*
** EPITECH PROJECT, 2020
** XmlEntity.cpp.cc
** File description:
** header for XmlEntity.c
*/

#include "engine/config/XmlEntity.hpp"
#include "default/TransformComponent.hpp"

namespace Polymorph
{
    std::shared_ptr<Entity> Polymorph::Config::XmlEntity::makeInstance(std::shared_ptr<Entity> &parent)
    {
        std::shared_ptr<Entity> e(new Entity(*this, parent));

        for (auto &c: _components)
        {
            std::string t = c->getType();
            (*e).addComponent(t, *c);
        }
        e->transform = e->GetComponent<TransformComponent>();
        if (parent != nullptr)
            e->transform->SetParent(parent->transform);

        for (auto &child: _children)
            std::shared_ptr<Entity> child_entity = child->makeInstance(e);


        return e;
    }

    std::shared_ptr<Entity> Config::XmlEntity::makeInstance()
    {
        std::shared_ptr<Entity> e(new Entity(*this));

        for (auto &c: _components)
        {
            std::string t = c->getType();
            (*e).addComponent(t, *c);
        }
        e->transform = e->GetComponent<TransformComponent>();
        for (auto &child: _children)
            std::shared_ptr<Entity> child_entity = child->makeInstance(e);
        return e;
    }
}
