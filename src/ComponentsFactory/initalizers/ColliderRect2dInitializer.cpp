/*
** EPITECH PROJECT, 2022
** ColliderRect2dInitializer.cpp
** File description:
** ColliderRect2dInitializer.cpp
*/

#include <Polymorph/Core.hpp>
#include <Polymorph/Debug.hpp>
#include <Polymorph/Factory.hpp>
#include <Polymorph/Config.hpp>
#include <Polymorph/Components.hpp>

Polymorph::ColliderRect2dInitializer::ColliderRect2dInitializer(Polymorph::Config::XmlComponent &data, GameObject entity)
        : AComponentInitializer("ColliderCircle2d", data, entity)
{
}
void Polymorph::ColliderRect2dInitializer::build()
{
    data.setProperty("size", component->size, Logger::MINOR);
    data.setProperty("offset", component->offset);
}
