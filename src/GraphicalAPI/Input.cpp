/*
** EPITECH PROJECT, 2020
** Input.cpp
** File description:
** header for Input.c
*/

#include <Polymorph/Debug.hpp>
#include <Polymorph/Core.hpp>
#include <Polymorph/Types.hpp>

bool Polymorph::Input::isKeyHold(arcade::KeyCode code)
{
    return GraphicalAPI::CurrentDisplay->isKeyPressed(code);
}

bool Polymorph::Input::isMouseButtonHold(arcade::KeyCode buttonNb)
{
    if (buttonNb < arcade::MouseButton1 || buttonNb > arcade::MouseButton3)
        return false;
    return GraphicalAPI::CurrentDisplay->isKeyPressed(buttonNb);
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

bool Polymorph::Input::isMouseButtonDown(arcade::KeyCode buttonNb)
{
    Logger::log("[Input] isMouseButtonDown: not implemented yet (false by default)");
    return false;
}

bool Polymorph::Input::isMouseButtonUp(arcade::KeyCode buttonNb)
{
    Logger::log("[Input] isMouseButtonUp: not implemented yet (false by default)");
    return false;
}
