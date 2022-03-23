/*
** EPITECH PROJECT, 2022
** ColliderCircle2dInitializer.cpp
** File description:
** ColliderCircle2dInitializer.cpp
*/


#include "default/Colliders/ColliderCircle2d.hpp"
#include "Engine/component/factory/initializers/ColliderCircle2dInitializer.hpp"
#include "XmlComponent.hpp"

Polymorph::ColliderCircle2dInitializer::ColliderCircle2dInitializer(Polymorph::Config::XmlComponent &data, Polymorph::Entity &entity)
        : AComponentInitializer("ColliderCircle2d", data, entity)
{
    component = std::shared_ptr<Component>(new ColliderCircle2dComponent(entity));
}

std::shared_ptr<Polymorph::Component> &Polymorph::ColliderCircle2dInitializer::build()
{
    auto trm = std::dynamic_pointer_cast<ColliderCircle2dComponent>(component);

    data.setProperty("radius", trm->radius, Logger::MINOR);
    data.setProperty("offset", trm->offset);

    return component;
}
