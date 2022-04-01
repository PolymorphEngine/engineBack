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

std::vector<arcade::KeyCode> Polymorph::Input::getHoldInputs()
{
    std::vector<arcade::KeyCode> keys;
    
    for (auto input: GraphicalAPI::CurrentDisplay->_holdedKeys) {
        if (input.second)
            keys.push_back(input.first);
    }
    return keys;
}

std::vector<arcade::KeyCode> Polymorph::Input::getDownInputs()
{
    std::vector<arcade::KeyCode> keys;
    
    for (auto input: GraphicalAPI::CurrentDisplay->_pressedKeys) {
        if (input.second)
            keys.push_back(input.first);
    }
    return keys;
}

std::vector<arcade::KeyCode> Polymorph::Input::getUpInputs()
{
    std::vector<arcade::KeyCode> keys;
    
    for (auto input: GraphicalAPI::CurrentDisplay->_releasedKeys) {
        if (input.second)
            keys.push_back(input.first);
    }
    return keys;
}
