/*
** EPITECH PROJECT, 2020
** AComponentInitializer.cpp
** File description:
** AComponentInitializer.cpp
*/

#include "component/factory/ComponentInitializer.hpp"
#include "XmlComponent.hpp"
#include "Component.hpp"

namespace Polymorph
{
    AComponentInitializer::AComponentInitializer(const std::string &type, Config::XmlComponent &data,
    Entity &entity) : data(data), type(type)
    {}

    void AComponentInitializer::_init()
    {
        component->enabled = data.isEnabled();
    }
}
