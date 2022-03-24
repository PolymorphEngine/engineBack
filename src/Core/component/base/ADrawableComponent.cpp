/*
** EPITECH PROJECT, 2020
** DrawableComponent.cpp
** File description:
** DrawableComponent.cpp
*/

#include <Polymorph/Core.hpp>
#include <Polymorph/Components.hpp>

namespace Polymorph
{
    ADrawableComponent::ADrawableComponent(std::string type, Entity &gameObject)
    : Component(type, gameObject)
    {
        
    }
}