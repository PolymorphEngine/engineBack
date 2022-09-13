/*
** EPITECH PROJECT, 2020
** GraphicalAPI.cpp
** File description:
** header for GraphicalAPI.c
*/

#include <Polymorph/Core.hpp>
#include <Polymorph/Types.hpp>
#include <Polymorph/Debug.hpp>
#include <Polymorph/Settings.hpp>
#include <utility>
#include "GraphicalAPI/GraphicalAPI.hpp"


Polymorph::GraphicalAPI::GraphicalAPI(std::string handlerPath)
{
    _handlerPath = std::move(handlerPath);
    if (_instance != nullptr)
        throw GraphicalException("Cannot create several Graphical API instance at once.", Logger::MAJOR);
    _instance = this;
}


#ifdef _WIN32
HINSTANCE Polymorph::GraphicalAPI::getHandler()
{
    if (!_instance)
        return nullptr;
    return _instance->_handler;
}
#else
void *Polymorph::GraphicalAPI::getHandler()
{
    if (!_instance)
        return nullptr;
    return _instance->_handler;
}

#endif

Polymorph::GraphicalAPI::~GraphicalAPI()
{
    CurrentDisplay.reset();
    _displays.clear();
    _instance = nullptr;
}

void Polymorph::GraphicalAPI::reloadAPI(const std::string& newHandler)
{
    if (!_instance)
    {
        Logger::log("No Graphic API handler available to reload.", Logger::MAJOR);
        return;
    }
    _instance->loadHandler(newHandler);
    _instance->_handlerPath = newHandler;
}

Polymorph::Display Polymorph::GraphicalAPI::createDisplay(std::shared_ptr<Settings::VideoSettings> &videoSettings, const std::string &title)
{
    auto n = std::make_shared<DisplayModule>(videoSettings, title);

    _instance->_displays.push_back(n);
    return Display(n);
}


