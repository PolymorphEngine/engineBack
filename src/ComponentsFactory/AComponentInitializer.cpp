/*
** EPITECH PROJECT, 2020
** AComponentInitializer.cpp
** File description:
** AComponentInitializer.cpp
*/

#include <Polymorph/Core.hpp>
#include <Polymorph/Factory.hpp>
#include <Polymorph/Config.hpp>
#include <Polymorph/Components.hpp>
#include <utility>

namespace Polymorph
{
    AComponentInitializer::AComponentInitializer(std::string type, Config::XmlComponent &data,
    Entity &entity) : data(data), type(std::move(type))
    {}

    void AComponentInitializer::_init()
    {
        component->enabled = data.isEnabled();
    }
}
