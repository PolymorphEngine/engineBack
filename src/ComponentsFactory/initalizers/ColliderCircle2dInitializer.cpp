/*
** EPITECH PROJECT, 2022
** ColliderCircle2dInitializer.cpp
** File description:
** ColliderCircle2dInitializer.cpp
*/


#include <Polymorph/Core.hpp>
#include <Polymorph/Debug.hpp>
#include <Polymorph/Factory.hpp>
#include <Polymorph/Config.hpp>
#include <Polymorph/Components.hpp>

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
