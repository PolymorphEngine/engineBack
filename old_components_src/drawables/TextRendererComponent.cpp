/*
** EPITECH PROJECT, 2020
** TextRendererComponent.cpp
** File description:
** TextRendererComponent.cpp
*/

#include <Polymorph/Core.hpp>
#include <Polymorph/Components.hpp>
#include <Polymorph/Types.hpp>

namespace Polymorph
{

    void TextRendererComponent::draw(Canvas canvas)
    {
        text->setPosition(Vector2(transform->getPosition()) + offset);
        text->draw();
    }

    TextRendererComponent::TextRendererComponent(GameObject gameObject)
            : ADrawable2dComponent("TextRenderer", gameObject)
    {

    }

}