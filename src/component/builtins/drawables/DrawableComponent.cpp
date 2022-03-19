/*
** EPITECH PROJECT, 2020
** DrawableComponent.cpp
** File description:
** DrawableComponent.cpp
*/

#include "default/drawables/DrawableComponent.hpp"

namespace Polymorph
{
    DrawableComponent::DrawableComponent(std::string type, Entity &gameObject)
    : Component(type, gameObject)
    {
        
    }
}