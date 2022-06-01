/*
** EPITECH PROJECT, 2020
** Sprite.cpp
** File description:
** header for Sprite.c
*/

#include <Polymorph/Core.hpp>
#include <Polymorph/Debug.hpp>
#include <Polymorph/Types.hpp>
#include <Polymorph/Config.hpp>
#include <GraphicalAPI/arcade/ISpriteModule.hpp>
#include <utility>
#include "GraphicalAPI/modules/SpriteModule.hpp"


void Polymorph::SpriteModule::_loadModule()
{
    setSprite(_filePath);
    setCrop(_crop);
}

Polymorph::SpriteModule::SpriteModule(std::string filePath)
{
    _filePath = std::move(filePath);

    _loadModule();
}

Polymorph::SpriteModule::SpriteModule(std::shared_ptr<myxmlpp::Node> &data, Config::XmlComponent &manager)
{
    manager.setSubProperty("_filePath", data, _filePath);
    _filePath = "./Game/Assets/" + _filePath;
    manager.setSubProperty("_crop", data, _crop);
    manager.setSubProperty("_color", data, _color);
    
    _spriteModule = GraphicalAPI::_c_sprite();
    _loadModule();
}


Polymorph::SpriteModule::~SpriteModule()
{
    if (_spriteModule != nullptr && GraphicalAPI::_d_sprite != nullptr)
    {
        GraphicalAPI::_d_sprite(_spriteModule);
        _spriteModule = nullptr;
    }
}

arcade::ISpriteModule *Polymorph::SpriteModule::getSprite()
{
    return _spriteModule;
}

void Polymorph::SpriteModule::setSprite(const std::string& newFilePath)
{
    _filePath = newFilePath;
    if (_spriteModule)
        try {
            _spriteModule->setSprite(newFilePath);
        } catch (std::exception &e) {
            throw GraphicalException("Sprite setSprite exception: " + std::string(e.what()), Logger::MINOR);
        }
    else
        Logger::log("No Sprite Object loaded", Logger::DEBUG);
}

void Polymorph::SpriteModule::setPosition(Polymorph::Vector2 position)
{
    if (_spriteModule)
        try {
            _spriteModule->setPosition(position.x, position.y);
        } catch (std::exception &e) {
            throw GraphicalException("Sprite setPosition exception: " + std::string(e.what()), Logger::MINOR);
        }
    else
        Logger::log("No Sprite Object loaded", Logger::DEBUG);
}

void Polymorph::SpriteModule::moveSprite(Polymorph::Vector2 move)
{
    if (_spriteModule)
        try {
            _spriteModule->move(move.x, move.y);
        } catch (std::exception &e) {
            throw GraphicalException("Sprite Move exception: " + std::string(e.what()), Logger::MINOR);
        }
    else
        Logger::log("No Sprite Object loaded", Logger::DEBUG);
}

void Polymorph::SpriteModule::setCrop(const Polymorph::Rect& crop)
{
    _crop = crop;

    if (_spriteModule)
        try {
            if (_crop.x > -1 && _crop.y > -1 && _crop.width > 0 && _crop.height > 0)
                _spriteModule->setCrop((int)_crop.x, (int)_crop.y, (int)_crop.width, (int)_crop.height);
        } catch (std::exception &e) {
            throw GraphicalException("Sprite Crop exception: " + std::string(e.what()), Logger::MINOR);
        }
    else
        Logger::log("No Sprite Object loaded", Logger::DEBUG);
}

Polymorph::Rect Polymorph::SpriteModule::getCrop() const
{
    return _crop;
}

void Polymorph::SpriteModule::setColor(Polymorph::Color color)
{
    _color = color;

    if (_spriteModule)
        try {
            _spriteModule->setColor(this->_color.r, this->_color.g, this->_color.b);
        } catch (std::exception &e) {
            throw GraphicalException("Sprite setColor exception: " + std::string(e.what()), Logger::MINOR);
        }
    else
        Logger::log("No Sprite Object loaded", Logger::DEBUG);
}
