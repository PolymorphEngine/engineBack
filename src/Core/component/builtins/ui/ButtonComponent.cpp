/*
** EPITECH PROJECT, 2020
** ButtonScript.cpp
** File description:
** ButtonScript implementation
*/

#include "Polymorph/Core.hpp"
#include "Polymorph/Components.hpp"
#include "Polymorph/Events.hpp"
#include "Core/component/builtins/ui/ButtonComponent.hpp"

namespace Polymorph
{
    ButtonComponent::ButtonComponent(GameObject gameObject)
            : Component("Button", gameObject) {}

    // Called only once when the Script is enabled the first time
    void ButtonComponent::start()
    {
        if (!!Target)
            _defaultTexture = Target->sprite;
        _delayTimer = Timer(0.5);
    }

    // Called every frame by the engine
    void ButtonComponent::update()
    {
        _delayTimer.tick();
        if (!_delayTimer.timeIsUp(false))
            return;
        if (!Target || Target->sprite == nullptr)
            return;
        auto rect = Target->sprite->getCrop();
        auto pos = Target->transform->getPosition();
        auto mouse_pos = Input::getMousePosition();
        rect.x = pos.x + Target->offset.x;
        rect.y = pos.y + Target->offset.y;

        if (!rect.contains(mouse_pos)) {
            Target->sprite = _defaultTexture;
            return;
        }
        Target->sprite = HoverTexture;
        if (Input::isMouseButtonPressed(Input::MouseButton::LEFT_BUTTON))
        {
            Target->sprite = ClickTexture;
            if (!!onClickHandler)
            {
                auto handler = onClickHandler->getComponent<IButtonHandler>();
                if (! ! handler)
                    handler->onButtonPressed(Target->gameObject);
            }
        }
        if (SceneManager::isSceneUnloaded())
            return;
        if (Input::isMouseButtonDown(Input::MouseButton::LEFT_BUTTON))
        {
            Target->sprite = ClickTexture;
            if (!!onHoldHandler)
            {
                auto handler = onHoldHandler->getComponent<IButtonHandler>();
                if (!!handler)
                    handler->onButtonDown(Target->gameObject);
            }
        }
        if (SceneManager::isSceneUnloaded())
            return;
        if (Input::isMouseButtonReleased(Input::MouseButton::LEFT_BUTTON))
        {
            Target->sprite = HoverTexture;
            if (!!onReleaseHandler)
            {
                auto handler = onReleaseHandler->getComponent<IButtonHandler>();
                if (!!handler)
                    handler->onButtonReleased(Target->gameObject);
            }
        }
    }

}