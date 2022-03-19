/*
** EPITECH PROJECT, 2020
** SpriteRendererComponent.cpp
** File description:
** SpriteRendererComponent.cpp
*/

#include "default/drawables/SpriteRendererComponent.hpp"
#include "default/TransformComponent.hpp"
#include "GraphicalAPI/Sprite.hpp"
#include "GraphicalAPI/Display.hpp"

namespace Polymorph
{

    void SpriteRendererComponent::draw()
    {
        if (!sprite)
            return;
        sprite->setPosition(Vector2(transform.getPosition()) + offset);
        Display::draw(*sprite);
    }
}