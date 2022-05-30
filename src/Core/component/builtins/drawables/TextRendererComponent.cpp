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

    void TextRendererComponent::draw()
    {
        text.setPosition(Vector2(transform->getPosition()) + offset);
        GraphicalAPI::CurrentDisplay->draw(text);
    }

    TextRendererComponent::TextRendererComponent(GameObject gameObject)
            : ADrawableComponent("TextRenderer", gameObject)
    {

    }

}