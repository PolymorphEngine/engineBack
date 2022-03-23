/*
** EPITECH PROJECT, 2020
** GraphicalAPI.cpp
** File description:
** header for GraphicalAPI.c
*/

#include "GraphicalAPI/GraphicalAPI.hpp"
#include "GraphicalAPI/DisplayModule.hpp"
#include "GraphicalException.hpp"

Polymorph::GraphicalAPI::GraphicalAPI(std::string handlerPath)
{
    _handlerPath = handlerPath;
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
    _unloadModules();
    _sprites.clear();
    _texts.clear();
    _displays.clear();
}


void Polymorph::GraphicalAPI::_unloadModules()
{
    for (auto &s: _instance->_sprites)
    {
        _instance->_d_sprite(s->_spriteModule);
        s->_spriteModule = nullptr;
    }
    for (auto &t: _instance->_texts)
    {
        _instance->_d_text(t->_textModule);
        t->_textModule = nullptr;
    }
    for (auto &t: _instance->_displays)
    {
        _instance->_d_display(t->_displayModule);
        t->_displayModule = nullptr;
    }
}

void Polymorph::GraphicalAPI::_reloadModules()
{
    for (auto &s: _instance->_sprites)
    {
        s->_spriteModule = _instance->_c_sprite();
        s->_loadModule();
    }
    for (auto &t: _instance->_texts)
    {
        t->_textModule = _instance->_c_text();
        t->_loadModule();
    }
    for (auto &t: _instance->_displays)
    {
        t->_displayModule = _instance->_c_display();
        t->_loadModule();
    }
}

void Polymorph::GraphicalAPI::reloadAPI(std::string newHandler)
{
    if (!_instance)
    {
        Logger::log("No Graphic API handler available to reload.", Logger::MAJOR);
        return;
    }
    _unloadModules();
    _instance->loadHandler(newHandler);

    _instance->_c_text = loadSymbol<TextLoader, GraphicalAPI>("createText");
    _instance->_c_sprite = loadSymbol<SpriteLoader, GraphicalAPI>("createSprite");
    _instance->_c_display = loadSymbol<DisplayLoader, GraphicalAPI>("createDisplay");

    _instance->_d_display = loadSymbol<DisplayUnloader, GraphicalAPI>("deleteDisplay");
    _instance->_d_sprite = loadSymbol<SpriteUnloader, GraphicalAPI>("destroySprite");
    _instance->_d_text = loadSymbol<TextUnloader, GraphicalAPI>("destroyText");

    _reloadModules();
}

Polymorph::Text
Polymorph::GraphicalAPI::createText(std::shared_ptr<myxmlpp::Node> &data)
{
    if (!_instance)
    {
        Logger::log("No GraphicalAPI available to create new Text.", Logger::MAJOR);
        return Text(nullptr);
    }
    TextBase newText = std::make_shared<TextModule>(data);
    
    newText->_textModule = _instance->_c_text();
    newText->_loadModule();
    
    _instance->_texts.push_back(newText);
    return Text(newText);
}

Polymorph::Sprite
Polymorph::GraphicalAPI::createSprite(std::shared_ptr<myxmlpp::Node> &data)
{
    if (!_instance || !_instance->_c_sprite)
    {
        Logger::log("No GraphicalAPI available to create new Sprite.", Logger::MAJOR);
        return Sprite(nullptr);
    }
    SpriteBase newSprite = std::make_shared<SpriteModule>(data);

    newSprite->_spriteModule = _instance->_c_sprite();
    newSprite->_loadModule();

    _instance->_sprites.push_back(newSprite);
    return Sprite(newSprite);
}

Polymorph::Display Polymorph::GraphicalAPI::createDisplay(
        std::shared_ptr<Settings::VideoSettings> videoSettings,
        std::string title)
{
    if (!_instance || !_instance->_c_display)
    {
        Logger::log("No GraphicalAPI available to create new Display.", Logger::MAJOR);
        return Display(nullptr);
    }
    DisplayBase newDisplay = std::make_shared<DisplayModule>(videoSettings, title);
    
    newDisplay->_displayModule = _instance->_c_display();
    newDisplay->_loadModule();
    
    _instance->_displays.push_back(newDisplay);
    return Display(newDisplay);
}

Polymorph::Text
Polymorph::GraphicalAPI::createText(unsigned int size, std::string fontPath,
                                    std::string text)
{
    if (!_instance)
    {
        Logger::log("No GraphicalAPI available to create new Text.", Logger::MAJOR);
        return Text(nullptr);
    }
    TextBase newText = std::make_shared<TextModule>(fontPath, text, size);

    newText->_textModule = _instance->_c_text();
    newText->_loadModule();

    _instance->_texts.push_back(newText);
    return Text(newText);
}

Polymorph::Sprite Polymorph::GraphicalAPI::createSprite(std::string filePath)
{
    if (!_instance)
    {
        Logger::log("No GraphicalAPI available to create new Sprite.", Logger::MAJOR);
        return Sprite(nullptr);
    }
    SpriteBase newSprite = std::make_shared<SpriteModule>(filePath);

    newSprite->_spriteModule = _instance->_c_sprite();
    newSprite->_loadModule();

    _instance->_sprites.push_back(newSprite);
    return Sprite(newSprite);
}

void Polymorph::GraphicalAPI::destroySprite(SpriteModule *sprite)
{
    auto fnc = [&sprite](SpriteBase &t) -> bool{ return (t.get() == sprite);};
    if (!_instance || !_instance->_d_sprite)
        throw GraphicalException("No GraphicalAPI available to destroy Sprite.", Logger::MAJOR);
    
    _instance->_d_sprite(sprite->_spriteModule);
    _instance->_sprites.erase(std::find_if(_instance->_sprites.begin(), _instance->_sprites.end(), fnc));
}

void Polymorph::GraphicalAPI::destroyText(TextModule *text)
{
    auto fnc = [&text](TextBase &t) -> bool{ return (t.get() == text);};

    if (!_instance || !_instance->_d_text)
        throw GraphicalException("No GraphicalAPI available to destroy Text.", Logger::MAJOR);
    
    _instance->_d_text(text->_textModule);
    _instance->_texts.erase(std::find_if(_instance->_texts.begin(), _instance->_texts.end(), fnc));
}

void Polymorph::GraphicalAPI::destroyDisplay(DisplayModule *display)
{
    auto fnc = [&display](DisplayBase &t) -> bool{ return (t.get() == display);};
    if (!_instance || !_instance->_d_display)
        throw GraphicalException("No GraphicalAPI available to destroy Display.", Logger::MAJOR);
    
    _instance->_d_display(display->_displayModule);
    _instance->_displays.erase(std::find_if(_instance->_displays.begin(), _instance->_displays.end(), fnc));
    
}
