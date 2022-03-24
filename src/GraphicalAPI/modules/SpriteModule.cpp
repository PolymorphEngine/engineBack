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

void Polymorph::SpriteModule::_loadModule()
{
    setSprite(_filePath);
    setCrop(_crop);
}

Polymorph::SpriteModule::SpriteModule(std::string filePath)
{
    _sprites.push_back(this);
    _filePath = filePath;
    
    _loadModule();
}

Polymorph::SpriteModule::~SpriteModule()
{
    GraphicalAPI::destroySprite(this);
}


arcade::ISpriteModule *Polymorph::SpriteModule::getSprite()
{
    return _spriteModule;
}

void Polymorph::SpriteModule::setSprite(std::string newFilePath)
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

void Polymorph::SpriteModule::setPosition(Polymorph::Vector2 position)
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

void Polymorph::SpriteModule::moveSprite(Polymorph::Vector2 move)
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

void Polymorph::SpriteModule::setCrop(Polymorph::Rect crop)
{
    _crop = crop;
    
    if (_spriteModule)
        try {
            if (_crop.x > -1 && _crop.y > -1 && _crop.width > 0 && _crop.height > 0)
                _spriteModule->setCrop(_crop.x, _crop.y, _crop.width, _crop.height);
        } catch (std::exception &e) {
            throw GraphicalException("Sprite Crop exception: " + std::string(e.what()), Logger::DEBUG);
        }
    else
        Logger::log("No Sprite Object loaded", Logger::DEBUG);
}

void Polymorph::SpriteModule::setColor(Polymorph::Color color)
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

Polymorph::SpriteModule::SpriteModule(std::shared_ptr<myxmlpp::Node> &data)
{
    Config::XmlComponent::setProperty("filepath", _filePath, data);
    Config::XmlComponent::setProperty("crop", _crop, data);
    Config::XmlComponent::setProperty("color", _color, data);
}
