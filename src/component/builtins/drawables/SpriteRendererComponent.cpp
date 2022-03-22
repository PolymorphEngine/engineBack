/*
** EPITECH PROJECT, 2020
** SpriteRendererComponent.cpp
** File description:
** SpriteRendererComponent.cpp
*/

#include "default/drawables/SpriteRendererComponent.hpp"
#include "default/TransformComponent.hpp"
#include "GraphicalAPI/SpriteModule.hpp"
#include "GraphicalAPI/DisplayModule.hpp"

namespace Polymorph
{

    void SpriteRendererComponent::draw()
    {
        if (!sprite)
            return;
        sprite->setPosition(Vector2(transform.getPosition()) + offset);
        GraphicalAPI::CurrentDisplay->draw(**sprite);
    }

    SpriteRendererComponent::SpriteRendererComponent(Entity &gameObject)
            : ADrawableComponent("SpriteRenderer", gameObject)
    {

    }
}