/*
** EPITECH PROJECT, 2020
** HorizontalGroupLayoutScript.cpp
** File description:
** HorizontalGroupLayoutScript implementation
*/

#include <Polymorph/Core.hpp>
#include <Polymorph/Components.hpp>
#include "Core/Component/builtins/ui/HorizontalGroupLayoutComponent.hpp"

namespace Polymorph
{
    HorizontalGroupLayoutComponent::HorizontalGroupLayoutComponent(GameObject gameObject)
            : Component("HorizontalGroupLayout", gameObject)
    {}

    // Called only once when the Script is enabled the first time
    void HorizontalGroupLayoutComponent::start()
    {
        
    }

    // Called every frame by the engine
    void HorizontalGroupLayoutComponent::update()
    {
        auto viewPortPos = transform->getPosition();
        Rect viewPortSize;
        if (!!ViewPort)
            viewPortSize = ViewPort->sprite->getCrop();
        auto nbChildren = static_cast<float>(transform->nbChildren());
        auto actualWidth = LeftPadding;
        for (auto &child : **transform)
        {
            if (!child->gameObject->isActive())
            {
                nbChildren --;
                continue;
            }
        }
        for (auto &child : **transform)
        {
            if (!child->gameObject->isActive())
                continue;
            auto pos = Vector3(viewPortPos.x + actualWidth, viewPortPos.y + TopPadding, 0);
            child->transform->setPosition(pos);
            auto renderer = child->getComponent<SpriteRendererComponent>();
            float width = 0.0f;
            if (!!renderer && renderer->sprite)
            {
                Vector2 scale = renderer->sprite->scale;
                auto actual = renderer->sprite->getCrop();
                if (ControlChildWidth)
                    scale.x = ((viewPortSize.x /
                    nbChildren) + LeftPadding + RightPadding + (nbChildren * Spacing)) / actual.width;
                if (ControlChildHeight) //TODO: check maths
                    scale.y = ((viewPortSize.y - TopPadding) - DownPadding) / actual.height;
                if (ControlChildWidth || ControlChildHeight)
                    renderer->sprite->setScale(scale);
                width = actual.width * scale.x;
                //width = renderer->sprite->getSize().x;
                //child->setScale(scale);
            }
            actualWidth += width + Spacing;
        }
        actualWidth += RightPadding;
        if (ScaleViewPortWidth) {
            Vector2 scale = {actualWidth / viewPortSize.x, 1};
            ViewPort->sprite->setScale(scale);
        }
    }

}