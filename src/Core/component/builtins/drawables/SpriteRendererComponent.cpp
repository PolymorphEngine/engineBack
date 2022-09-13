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
    void SpriteRendererComponent::draw(Canvas canvas)
    {
        sprite->setPosition(Vector2(transform->getPosition()) + offset);
        sprite->draw();
    }

    SpriteRendererComponent::SpriteRendererComponent(GameObject gameObject)
            : ADrawable2dComponent("SpriteRenderer", gameObject)
    {

    }
}