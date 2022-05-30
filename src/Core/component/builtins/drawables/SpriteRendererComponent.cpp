/*
** EPITECH PROJECT, 2020
** SpriteRendererComponent.cpp
** File description:
** SpriteRendererComponent.cpp
*/

#include <Polymorph/Core.hpp>
#include <Polymorph/Components.hpp>
#include <Polymorph/Types.hpp>

namespace Polymorph
{

    void SpriteRendererComponent::draw()
    {
        sprite.setPosition(Vector2(transform->getPosition()) + offset);
        GraphicalAPI::CurrentDisplay->draw(sprite);
    }

    SpriteRendererComponent::SpriteRendererComponent(GameObject gameObject)
            : ADrawableComponent("SpriteRenderer", gameObject)
    {

    }
}