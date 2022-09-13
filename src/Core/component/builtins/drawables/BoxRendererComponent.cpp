/*
** EPITECH PROJECT, 2022
** BoxRendererComponent.cpp
** File description:
** BoxRendererComponent.cpp
*/

#include <Polymorph/Core.hpp>
#include <Polymorph/Components.hpp>
#include <Polymorph/Types.hpp>
#include "BoxRendererComponent.hpp"

namespace Polymorph
{
    BoxRendererComponent::BoxRendererComponent(GameObject gameObject)
            : ADrawable3dComponent("BoxRenderer", gameObject)
    {
    }

    void BoxRendererComponent::start()
    {
        box->setTexture(texture);
    }

    void BoxRendererComponent::draw()
    {
        box->setOrigin(Vector3(transform->getPosition()) + offset);
        box->draw();
    }

    void BoxRendererComponent::setTexture(const std::shared_ptr<TextureModule>& texture)
    {
        this->texture = texture;
        box->setTexture(texture);
    }

}