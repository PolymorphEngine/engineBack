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
}

void Polymorph::ColliderCircle2dInitializer::build()
{
    data.setProperty("radius", component->radius, Logger::MINOR);
    data.setProperty("offset", component->offset);
}
