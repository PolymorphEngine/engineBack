/*
** EPITECH PROJECT, 2022
** Text.cpp
** File description:
** Text.cpp
*/


#include "GraphicalAPI/Text.hpp"
#include "GraphicalAPI/DynamicLoader.hpp"
#include "Log/Logger.hpp"
#include "GraphicalException.hpp"
#include "XmlComponent.hpp"

#include <utility>

Polymorph::Text::Text(std::string fontPath, std::string text)
        : _filepath(std::move(fontPath)), _str(std::move(text))
{
    _loadModule();
    _texts.push_back(this);
}

Polymorph::Text::Text(std::shared_ptr<myxmlpp::Node> &data)
{
    _texts.push_back(this);

    if (!create || !destroy)
    {
        try {
            create = DynamicLibLoader::loadSymbol<loader>("createSprite");
            destroy = DynamicLibLoader::loadSymbol<unloader>("destroySprite");
        } catch(const GraphicalException &e) {
            e.what();
            throw GraphicalException("Error loading sprite module symbols", Logger::MINOR);
        }
    }
    _textModule = create();

    Config::XmlComponent::setPropertyFromAttr("filepath", _filepath, data);
    Config::XmlComponent::setPropertyFromAttr("string", _str, data);
    Config::XmlComponent::setPropertyFromAttr("size", _fontSize, data);
    Config::XmlComponent::setProperty("color", _color, data);
    if (_fontSize)
        throw GraphicalException("Error ", Logger::MAJOR);
    if (_textModule)
        try {
            _textModule->setFont(_filepath);
            _textModule->setText(_str);
            _textModule->setColor(_color.r, _color.g, _color.b);
        } catch (std::exception &e) {
            throw GraphicalException("Text exception: " + std::string(e.what()), Logger::DEBUG);
        }
    else
        Logger::log("No Sprite Object loaded", Logger::DEBUG);
}

Polymorph::Text::~Text()
{
    _unloadModule();
    auto it = std::find(_texts.begin(), _texts.end(), this);
    _texts.erase(it);
}

arcade::ITextModule *Polymorph::Text::getText()
{
    return _textModule;
}

void Polymorph::Text::setFont(std::string newFilePath)
{
    _textModule->setFont(std::move(newFilePath));
}

void Polymorph::Text::setPosition(Polymorph::Vector2 position)
{
    _textModule->setPosition(position.x, position.y);
}

void Polymorph::Text::move(Polymorph::Vector2 move)
{
    _textModule->move(move.x, move.y);
}

void Polymorph::Text::setString(std::string newString)
{
    _textModule->setText(std::move(newString));
}

void Polymorph::Text::setColor(Polymorph::Color color)
{
    _color = color;

    if (_textModule)
        try {
            _textModule->setColor(_color.r, _color.g, _color.b);
        } catch (std::exception &e) {
            throw GraphicalException("Text setColor exception: " + std::string(e.what()), Logger::DEBUG);
        }
    else
        Logger::log("No Text Object loaded", Logger::DEBUG);
}

void Polymorph::Text::loadModules()
{
    try {
        create = DynamicLibLoader::loadSymbol<loader>("createSprite");
        destroy = DynamicLibLoader::loadSymbol<unloader>("destroySprite");
    } catch(const GraphicalException &e) {
        e.what();
        throw GraphicalException("Error loading sprite module symbols", Logger::MINOR);
    }
    for (auto &e: _texts)
        e->_loadModule();
}

void Polymorph::Text::unloadModules()
{
    for (auto &s: _texts)
        s->_unloadModule();
}

void Polymorph::Text::_loadModule()
{
    if (!create || !destroy)
    {
        loadModules();
        return;
    }
    _textModule = create();
    setFont(_filepath);
    setString(_str);
    setColor(_color);
}

void Polymorph::Text::_unloadModule()
{
    if (!create || !destroy) {
        try {
            create = DynamicLibLoader::loadSymbol<loader>("createSprite");
            destroy = DynamicLibLoader::loadSymbol<unloader>("destroySprite");
        } catch(const GraphicalException &e) {
            e.what();
            throw GraphicalException("Error loading sprite module symbols", Logger::MINOR);
        }
    }
    try {
        destroy(_textModule);
    } catch (std::exception &e) {
        throw GraphicalException("Destroy Sprite exception: " + std::string(e.what()), Logger::DEBUG);
    }
}

void Polymorph::Text::setFontSize(int size)
{
    _textModule->setSize(size);
}
