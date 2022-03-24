/*
** EPITECH PROJECT, 2022
** Text.cpp
** File description:
** Text.cpp
*/



#include <Polymorph/Core.hpp>
#include <Polymorph/Debug.hpp>
#include <Polymorph/Types.hpp>
#include <Polymorph/Config.hpp>
#include <GraphicalAPI/arcade/ITextModule.hpp>


Polymorph::TextModule::TextModule(std::string fontPath, std::string text, unsigned int size)
        : _filepath(std::move(fontPath)), _str(std::move(text))
{
    _loadModule();
}

Polymorph::TextModule::TextModule(std::shared_ptr<myxmlpp::Node> &data)
{
    Config::XmlComponent::setProperty("font", _filepath, data, Logger::MAJOR);
    Config::XmlComponent::setProperty("string", _str, data);
    Config::XmlComponent::setProperty("size", _fontSize, data, Logger::MAJOR);
    Config::XmlComponent::setProperty("color", _color, data);
}

Polymorph::TextModule::~TextModule()
{
    GraphicalAPI::destroyText(this);
}

arcade::ITextModule *Polymorph::TextModule::getText()
{
    return _textModule;
}

void Polymorph::TextModule::setFont(std::string newFilePath)
{
    if (_textModule)
        try {
            _textModule->setFont(std::move(newFilePath));
        } catch(std::exception &e) {
            throw GraphicalException("No text font found: " + std::string(e.what()), Logger::MAJOR);
        }
    else
        Logger::log("No text module loaded.", Logger::MINOR);

}

void Polymorph::TextModule::setPosition(Vector2 position)
{
    if (_textModule)
    _textModule->setPosition(position.x, position.y);
    else
        Logger::log("No text module loaded.", Logger::MINOR);
}

void Polymorph::TextModule::move(Vector2 move)
{
    if (_textModule)
    _textModule->move(move.x, move.y);
    else
        Logger::log("No text module loaded.", Logger::MINOR);

}

void Polymorph::TextModule::setString(std::string newString)
{
    if (_textModule)
        _textModule->setText(std::move(newString));
    else
        Logger::log("No text module loaded.", Logger::MINOR);

}

void Polymorph::TextModule::setColor(Polymorph::Color color)
{
    _color = color;

    if (_textModule)
        try {
            _textModule->setColor(_color.r, _color.g, _color.b);
        } catch (std::exception &e) {
            throw GraphicalException("Text setColor exception: " + std::string(e.what()), Logger::DEBUG);
        }
    else
        Logger::log("No text module loaded.", Logger::MINOR);
}

void Polymorph::TextModule::_loadModule()
{
    setFont(_filepath);
    setString(_str);
    setFontSize(_fontSize);
    setColor(_color);
}


void Polymorph::TextModule::setFontSize(int size)
{
    if (_textModule)
        _textModule->setSize(size);
    else
        Logger::log("No text module loaded.", Logger::MINOR);
}

Polymorph::TextModule &Polymorph::TextModule::operator=(const std::string &newText)
{
    if (_textModule)
        _textModule->setText(newText);
    else
        Logger::log("No text module loaded.", Logger::MINOR);
    return *this;
}

Polymorph::TextModule &Polymorph::TextModule::operator+=(const std::string &newText)
{
    if (_textModule)
        _textModule->setText(_str + newText);
    else
        Logger::log("No text module loaded.", Logger::MINOR);
    return *this;
}

std::string Polymorph::TextModule::operator+(const std::string &newText)
{
    return _str + newText;
}
