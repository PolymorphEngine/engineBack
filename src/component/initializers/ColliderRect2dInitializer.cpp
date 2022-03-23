/*
** EPITECH PROJECT, 2022
** ColliderRect2dInitializer.cpp
** File description:
** ColliderRect2dInitializer.cpp
*/

#include "default/Colliders/ColliderRect2d.hpp"
#include "Engine/component/factory/initializers/ColliderRect2dInitializer.hpp"
#include "XmlComponent.hpp"

Polymorph::ColliderRect2dInitializer::ColliderRect2dInitializer(Polymorph::Config::XmlComponent &data, Polymorph::Entity &entity)
        : AComponentInitializer("ColliderCircle2d", data, entity)
{
    component = std::shared_ptr<Component>(new ColliderRect2dComponent(entity));
}

std::shared_ptr<Polymorph::Component> &Polymorph::ColliderRect2dInitializer::build()
{
    auto trm = std::dynamic_pointer_cast<ColliderRect2dComponent>(component);

    data.setProperty("size", trm->size, Logger::MINOR);
    data.setProperty("offset", trm->offset);

    return component;
}
