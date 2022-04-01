/*
** EPITECH PROJECT, 2020
** Input.cpp
** File description:
** header for Input.c
*/

#include <Polymorph/Debug.hpp>
#include <Polymorph/Core.hpp>
#include <Polymorph/Types.hpp>
#include "GraphicalAPI/Input.hpp"


bool Polymorph::Input::isKeyHold(arcade::KeyCode code)
{
    return GraphicalAPI::CurrentDisplay->_holdedKeys[code];
}

bool Polymorph::Input::isMouseButtonHold(arcade::KeyCode buttonNb)
{
    return GraphicalAPI::CurrentDisplay->_holdedKeys[buttonNb];
}

bool Polymorph::Input::isKeyUp(arcade::KeyCode code)
{
    return GraphicalAPI::CurrentDisplay->_releasedKeys[code];
}

bool Polymorph::Input::isKeyDown(arcade::KeyCode code)
{
    return GraphicalAPI::CurrentDisplay->_pressedKeys[code];
}

bool Polymorph::Input::isMouseButtonDown(arcade::KeyCode buttonNb)
{
    
    return GraphicalAPI::CurrentDisplay->_pressedKeys[buttonNb];
}

bool Polymorph::Input::isMouseButtonUp(arcade::KeyCode buttonNb)
{
    return GraphicalAPI::CurrentDisplay->_releasedKeys[buttonNb];

}

std::vector<arcade::KeyCode> Polymorph::Input::getCurrentInputs()
{
    std::vector<arcade::KeyCode> keys;
    for (int i = 0; i < arcade::KeyCount; i++) {
        if (GraphicalAPI::CurrentDisplay->isKeyPressed(static_cast<arcade::KeyCode>(i)))
            keys.push_back(static_cast<arcade::KeyCode>(i));
    }
    if (GraphicalAPI::CurrentDisplay->isKeyPressed(arcade::MouseButton1))
        keys.push_back(arcade::MouseButton1);
    if (GraphicalAPI::CurrentDisplay->isKeyPressed(arcade::MouseButton2))
        keys.push_back(arcade::MouseButton2);
    if (GraphicalAPI::CurrentDisplay->isKeyPressed(arcade::MouseButton3))
        keys.push_back(arcade::MouseButton3);
    return keys;
}
