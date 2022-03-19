/*
** EPITECH PROJECT, 2020
** Sprite.cpp
** File description:
** header for Sprite.c
*/

#include "GraphicalAPI/Sprite.hpp"
#include "GraphicalAPI/DynamicLoader.hpp"
#include "Log/Logger.hpp"
#include "GraphicalException.hpp"

void Polymorph::Sprite::loadModules()
{
    try {
        create = DynamicLibLoader::loadSymbol<loader>("createSprite");
        destroy = DynamicLibLoader::loadSymbol<unloader>("destroySprite");
    } catch(const GraphicalException &e) {
        e.what();
        throw GraphicalException("Error loading sprite module symbols", Logger::MINOR);
    }
    for (auto &s: _sprites)
        s->_loadModule();
}

void Polymorph::Sprite::unloadModules()
{
    for (auto &s: _sprites)
        s->_unloadModule();
    create = nullptr;
    destroy = nullptr;
}

void Polymorph::Sprite::_unloadModule()
{
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
    try
    {
        destroy(_spriteModule);
    } catch (std::exception &e) {
        throw GraphicalException("Destroy Sprite exception: " + std::string(e.what()), Logger::DEBUG);
    }
}

void Polymorph::Sprite::_loadModule()
{
    if (!create || !destroy)
    {
        loadModules();
        return;
    }
    _spriteModule = create();
    setSprite(_filePath);
    setCrop(_crop);
}

Polymorph::Sprite::Sprite(std::string filePath)
{
    _sprites.push_back(this);
    _filePath = filePath;
    
    _loadModule();
}

Polymorph::Sprite::~Sprite()
{
    if (!create || !destroy)
    {
        try {
            create = DynamicLibLoader::loadSymbol<loader>("createSprite");
            destroy = DynamicLibLoader::loadSymbol<unloader>("destroySprite");
        } catch(const GraphicalException &e) {
            e.what();
            return;
        }
    }
    _unloadModule();
    _sprites.erase(std::find(_sprites.begin(), _sprites.end(), this));
}

Polymorph::Sprite::Sprite()
{
    _sprites.push_back(this);
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
    _spriteModule = create();
}

arcade::ISpriteModule *Polymorph::Sprite::getSprite()
{
    return _spriteModule;
}

void Polymorph::Sprite::setSprite(std::string newFilePath)
{
    _filePath = newFilePath;
    if (_spriteModule)
        try {
            _spriteModule->setSprite(newFilePath);
        } catch (std::exception &e) {
            throw GraphicalException("Sprite setSprite exception: " + std::string(e.what()), Logger::DEBUG);
        }
    else
        Logger::log("No Sprite Object loaded", Logger::DEBUG);
}

void Polymorph::Sprite::setPosition(Polymorph::Vector2 position)
{
    if (_spriteModule)
        try {
            _spriteModule->setPosition(position.x, position.y);
        } catch (std::exception &e) {
            throw GraphicalException("Sprite setPosition exception: " + std::string(e.what()), Logger::DEBUG);
        }
    else
        Logger::log("No Sprite Object loaded", Logger::DEBUG);
}

void Polymorph::Sprite::moveSprite(Polymorph::Vector2 move)
{
    if (_spriteModule)
        try {
            _spriteModule->move(move.x, move.y);
        } catch (std::exception &e) {
            throw GraphicalException("Sprite Move exception: " + std::string(e.what()), Logger::DEBUG);
        }
    else
        Logger::log("No Sprite Object loaded", Logger::DEBUG);
}

void Polymorph::Sprite::setCrop(Polymorph::Rect crop)
{
    _crop = crop;
    
    if (_spriteModule)
        try {
            _spriteModule->setCrop(crop.x, crop.y, crop.width, crop.height);
        } catch (std::exception &e) {
            throw GraphicalException("Sprite Crop exception: " + std::string(e.what()), Logger::DEBUG);
        }
    else
        Logger::log("No Sprite Object loaded", Logger::DEBUG);
}

void Polymorph::Sprite::setColor(Polymorph::Color color)
{
    _color = color;

    if (_spriteModule)
        try {
            _spriteModule->setColor(this->_color.r, this->_color.g, this->_color.b);
        } catch (std::exception &e) {
            throw GraphicalException("Sprite setColor exception: " + std::string(e.what()), Logger::DEBUG);
        }
    else
        Logger::log("No Sprite Object loaded", Logger::DEBUG);
}

Polymorph::Sprite::Sprite(std::shared_ptr<myxmlpp::Node> &data)
{
    _sprites.push_back(this);

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
    _spriteModule = create();

    Config::XmlComponent::setPropertyFromAttr("filepath", _filePath, data);
    Config::XmlComponent::setProperty("crop", _crop, data);
    Config::XmlComponent::setProperty("color", _color, data);
    if (_spriteModule)
        try {
            _spriteModule->setSprite(_filePath);
        } catch (std::exception &e) {
            throw GraphicalException("Sprite setSprite exception: " + std::string(e.what()), Logger::DEBUG);
        }
    else
        Logger::log("No Sprite Object loaded", Logger::DEBUG);
}
