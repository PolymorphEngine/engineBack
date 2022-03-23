/*
** EPITECH PROJECT, 2020
** DrawableComponent.cpp
** File description:
** DrawableComponent.cpp
*/

#include "default/drawables/ADrawableComponent.hpp"

namespace Polymorph
{
    ADrawableComponent::ADrawableComponent(std::string type, Entity &gameObject)
    : Component(type, gameObject)
    {
        
    }
}