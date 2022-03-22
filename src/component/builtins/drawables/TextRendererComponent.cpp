/*
** EPITECH PROJECT, 2020
** TextRendererComponent.cpp
** File description:
** TextRendererComponent.cpp
*/

#include "default/drawables/TextRendererComponent.hpp"
#include "default/TransformComponent.hpp"
#include "GraphicalAPI/SpriteModule.hpp"
#include "GraphicalAPI/DisplayModule.hpp"

namespace Polymorph
{

    void TextRendererComponent::draw()
    {
        if (!text)
            return;
        text->setPosition(Vector2(transform.getPosition()) + offset);
        GraphicalAPI::CurrentDisplay->draw(**text);
    }

    TextRendererComponent::TextRendererComponent(Entity &gameObject)
            : ADrawableComponent("TextRenderer", gameObject)
    {

    }

}