/*
** EPITECH PROJECT, 2020
** InputFieldScript.cpp
** File description:
** InputFieldScript implementation
*/

#include "Polymorph/Core.hpp"
#include "Polymorph/Components.hpp"
#include "Polymorph/Events.hpp"
#include "Core/component/builtins/ui/InputFieldComponent.hpp"

namespace Polymorph
{
    InputFieldComponent::InputFieldComponent(GameObject gameObject)
            : Component("InputField", gameObject)
    {}

    // Called only once when the Script is enabled the first time
    void InputFieldComponent::start()
    {
    }

    // Called every frame by the engine
    void InputFieldComponent::update()
    {
        _updateFocus();
        if (!_isFocused || Input::getKeyPressed() == Input::NONE) return;
        if (Input::getKeyPressed() == Input::ENTER) {
            _isFocused = false;
            if (!!OnSubmit) {
                auto handler = OnSubmit->getComponent<IInputFieldHandler>();
                if (!!handler)
                    handler->onSubmit(Target->text->getString());
            }
        }
        else if (Input::getKeyPressed() == Input::DEL) {
            if (!Target->text->getString().empty())
                Target->text->setString(Target->text->getString().substr(0, Target->text->getString().size() - 1));
        }
        else {
            auto input = Input::getCharPressed();
            if (Type == InputType::Text_Only) {
                if (!(input >= 'a' && input <= 'z')
                && !(input >= 'A' && input <= 'Z'))
                    return;
                Target->text->setString(Target->text->getString() + input);
            }
            else if (Type == InputType::Numbers_Only) {
                if (!(input >= '0' && input <= '9'))
                    return;
                Target->text->setString(Target->text->getString() + input);
            }
            else
                Target->text->setString(Target->text->getString() + input);

        }
        if (!!OnValueChanged) {
            auto handler = OnValueChanged->getComponent<IInputFieldHandler>();
            if (!!handler)
                handler->onValueChanged(Target->text->getString());
        }

    }

    void InputFieldComponent::_updateFocus()
    {
        auto mouse_pos = Input::getMousePosition();
        auto pos = PlaceHolder->transform->getPosition();
        auto rect = PlaceHolder->sprite->getCrop();
        rect.x = pos.x;
        rect.y = pos.y;
        auto pressed = Input::isMouseButtonPressed(Input::MouseButton::LEFT_BUTTON);
        if (pressed && rect.contains(mouse_pos))
        {
            _isFocused = true;
        }
        else if (pressed && !rect.contains(mouse_pos))
        {
            if (_isFocused && !!OnExitFocus)
            {
                auto handler = OnExitFocus->getComponent<IInputFieldHandler>();
                if (!!handler)
                    handler->onExitFocus(Target->text->getString());
            }
            _isFocused = false;
        }
    }

}