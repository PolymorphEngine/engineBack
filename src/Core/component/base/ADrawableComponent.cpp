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
    ADrawable2dComponent::ADrawable2dComponent(std::string type, GameObject gameObject)
    : Component(type, gameObject)
    {
        
    }
}