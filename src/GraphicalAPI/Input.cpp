/*
** EPITECH PROJECT, 2020
** Input.cpp
** File description:
** header for Input.c
*/

#include "GraphicalAPI/Input.hpp"
#include "Log/Logger.hpp"

bool Polymorph::Input::isKeyHold(arcade::KeyCode code)
{
    GraphicalAPI::CurrentDisplay->isKeyPressed(code);
    return false;
}

bool Polymorph::Input::isMouseButtonHold(unsigned int buttonNb)
{
    if (buttonNb == 0 || buttonNb > 3)
        return false;
    auto c = static_cast<arcade::KeyCode>(arcade::KeyCount + buttonNb);
    
    GraphicalAPI::CurrentDisplay->isKeyPressed(c);
    return false;
}

bool Polymorph::Input::isKeyUp(arcade::KeyCode code)
{
    Logger::log("[Input] isKeyUp: not implemented yet (false by default)");
    return false;
}

bool Polymorph::Input::isKeyDown(arcade::KeyCode code)
{
    Logger::log("[Input] isKeyDown: not implemented yet (false by default)");
    return false;
}

bool Polymorph::Input::isMouseButtonDown(unsigned int buttonNb)
{
    Logger::log("[Input] isMouseButtonDown: not implemented yet (false by default)");
    return false;
}

bool Polymorph::Input::isMouseButtonUp(unsigned int buttonNb)
{
    Logger::log("[Input] isMouseButtonUp: not implemented yet (false by default)");
    return false;
}
