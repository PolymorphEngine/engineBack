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


void *Polymorph::GraphicalAPI::getHandler()
{
    if (!_instance)
        return nullptr;
    return _instance->_handler;
}

Polymorph::GraphicalAPI::~GraphicalAPI()
{
//    _unloadModules();
    CurrentDisplay.reset();
    _sprites.clear();
    _texts.clear();
    _displays.clear();
    _instance = nullptr;
}


//void Polymorph::GraphicalAPI::_unloadModules()
//{
//    for (auto &s: _instance->_sprites)
//    {
//        _instance->_d_sprite(s->_spriteModule);
//        s->_spriteModule = nullptr;
//    }
//    for (auto &t: _instance->_texts)
//    {
//        _instance->_d_text(t->_textModule);
//        t->_textModule = nullptr;
//    }
//    for (auto &t: _instance->_displays)
//    {
//        _instance->_d_display(t->_displayModule);
//        t->_displayModule = nullptr;
//    }
//}

//void Polymorph::GraphicalAPI::_reloadModules()
//{
//    for (auto &t: _instance->_displays) {
//        t->_displayModule = _instance->_c_display(10, 10, "");
//        t->_loadModule();
//    }
//    for (auto &s: _instance->_sprites) {
//        s->_spriteModule = _instance->_c_sprite();
//        s->_loadModule();
//    }
//    for (auto &t: _instance->_texts) {
//        t->_textModule = _instance->_c_text();
//        t->_loadModule();
//    }
//}

void Polymorph::GraphicalAPI::reloadAPI(const std::string& newHandler)
{
    if (!_instance)
    {
        Logger::log("No Graphic API handler available to reload.", Logger::MAJOR);
        return;
    }
//    _unloadModules();
    _instance->loadHandler(newHandler);

    _c_text = loadSymbol<TextLoader, GraphicalAPI>("createText");
    _c_sprite = loadSymbol<SpriteLoader, GraphicalAPI>("createSprite");
    _c_display = loadSymbol<DisplayLoader, GraphicalAPI>("createDisplay");

    _d_display = loadSymbol<DisplayUnloader, GraphicalAPI>("deleteDisplay");
    _d_sprite = loadSymbol<SpriteUnloader, GraphicalAPI>("deleteSprite");
    _d_text = loadSymbol<TextUnloader, GraphicalAPI>("deleteText");
    _instance->_handlerPath = newHandler;

//    _reloadModules();
}

std::string Polymorph::GraphicalAPI::getHandlerPath()
{
    if (!_instance)
    {
        Logger::log("No Graphic API handler available to reload.", Logger::MAJOR);
        return "";
    }
    return _instance->_handlerPath;
}
//
//void Polymorph::GraphicalAPI::destroySprite(SpriteModule *sprite)
//{
//    auto fnc = [&sprite](SpriteBase &t) -> bool{ return (t.get() == sprite);};
//    if (!_instance)
//        throw GraphicalException("No GraphicalAPI available to destroy Sprite.", Logger::MAJOR);
//    else if (!_instance->_d_sprite)
//        throw GraphicalException("No symbol available to destroy Sprite.", Logger::MAJOR);
//
//    _instance->_d_sprite(sprite->_spriteModule);
//    sprite->_spriteModule = nullptr;
//    auto it = std::find_if(_instance->_sprites.begin(), _instance->_sprites.end(), fnc);
//    if (it == _instance->_sprites.end())
//        return;
//    _instance->_sprites.erase(it);
//}
//
//void Polymorph::GraphicalAPI::destroyText(TextModule *text)
//{
//    auto fnc = [&text](TextBase &t) -> bool{ return (t.get() == text);};
//
//    if (!_instance)
//        throw GraphicalException("No GraphicalAPI available to destroy Text.", Logger::MAJOR);
//    else if (!_instance->_d_text)
//        throw GraphicalException("No symbol available to destroy Text.", Logger::MAJOR);
//    _instance->_d_text(text->_textModule);
//    text->_textModule = nullptr;
//    auto it = std::find_if(_instance->_texts.begin(), _instance->_texts.end(), fnc);
//    if (it == _instance->_texts.end())
//        return;
//    _instance->_texts.erase(it);
//
//}

Polymorph::Display Polymorph::GraphicalAPI::createDisplay(const std::shared_ptr<Settings::VideoSettings> &videoSettings, const std::string &title)
{
    auto n = std::make_shared<DisplayModule>(videoSettings, title);
    
    _instance->_displays.push_back(n);
    return Display(n);
}


void Polymorph::GraphicalAPI::destroyDisplay(DisplayModule *display)
{
    auto fnc = [&display](DisplayBase &t) -> bool{ return (t.get() == display);};
    if (!_instance)
        throw GraphicalException("No GraphicalAPI available to destroy Display.", Logger::MAJOR);
    else if (!_instance->_d_display)
        throw GraphicalException("No symbol available to destroy Display.", Logger::MAJOR);

    _instance->_d_display(display->_displayModule);
    display->_displayModule = nullptr;
    
    auto it = std::find_if(_instance->_displays.begin(), _instance->_displays.end(), fnc);
    if (it == _instance->_displays.end())
        return;
    _instance->_displays.erase(it);
}
