/*
** EPITECH PROJECT, 2022
** TextModule.cpp
** File description:
** TextModule.cpp
*/

#include <filesystem>
#include "GraphicalAPI/modules/TextModule.hpp"
#include "GraphicalAPI/GraphicalAPI.hpp"

Polymorph::TextModule::TextModule(std::string str, float size)
{
    _loadModules();
    _fontSize = size;
    _lineSpacing = 5;
    _textString = str;
    _fontFilepath = "";
    _checkFontPath();
    _text = std::unique_ptr<Polymorph::ITextModule>(_c_text(_textString));
    setFont(_fontFilepath);
    setFontSize(_fontSize);
    setSpacing(_lineSpacing);
    setColor(Color(255, 255, 255, 255));
}


Polymorph::TextModule::TextModule(std::shared_ptr<myxmlpp::Node> &data, Config::XmlComponent &manager)
    : _fontSize(15), _lineSpacing(4)
{
    _loadModules();
    manager.setSubProperty("_textString", data, _textString);
    manager.setSubProperty("_fontFilepath", data, _fontFilepath);
    _fontFilepath = "./Game/Assets/" + _fontFilepath;
    _checkFontPath();
    manager.setSubProperty("_fontSize", data, _fontSize);
    manager.setSubProperty("_lineSpacing", data, _lineSpacing);
    if (_lineSpacing == 0)
        _lineSpacing = 1;
    manager.setSubProperty("_color", data, _color);
    _text = std::unique_ptr<Polymorph::ITextModule>(_c_text(_textString));
    setFont(_fontFilepath);
    setFontSize(_fontSize);
    setSpacing(_lineSpacing);
    setColor(_color);
}

void Polymorph::TextModule::setPosition(Vector2 position)
{
	_text->setPosition(position.x, position.y);
}

void Polymorph::TextModule::setString(const std::string &content)
{
	_text->setText(content);
	_textString = content;
}

std::string Polymorph::TextModule::getString()
{
	return _textString;
}

void Polymorph::TextModule::setFont(const std::string &fontPath)
{
    _fontFilepath = fontPath;
    _font = std::unique_ptr<Polymorph::IFontModule>(_c_font(_fontFilepath));
}

void Polymorph::TextModule::setFontSize(float fontSize)
{
	_fontSize = fontSize;
}

float Polymorph::TextModule::getFontSize()
{
	return _fontSize;
}

void Polymorph::TextModule::setSpacing(float lineSpacing)
{
	_lineSpacing = lineSpacing;
}

float Polymorph::TextModule::getSpacing()
{
	return _lineSpacing;
}

void Polymorph::TextModule::setColor(Color color)
{
	_color = color;
    _text->setColor(color.r, color.g, color.b, color.a);
}

Polymorph::Color Polymorph::TextModule::getColor()
{
	return _color;
}

void Polymorph::TextModule::draw()
{
	_text->draw(*_font, _fontSize, _lineSpacing);
}

void Polymorph::TextModule::_loadModules()
{
    if (_c_text && _c_font)
        return;
    _c_text = GraphicalAPI::loadSymbol<TextModuleLoader, GraphicalAPI>("createTextModule");
    _c_font = GraphicalAPI::loadSymbol<FontModuleLoader, GraphicalAPI>("createFontModule");
}

void Polymorph::TextModule::_checkFontPath()
{
    if (std::filesystem::exists(_fontFilepath))
        return;
    if (std::filesystem::exists(_fallBackFont)) {
        _fontFilepath = _fallBackFont;
        Logger::log("Font path seems invalid, using default texture!", Logger::MINOR);
        return;
    }
    Logger::log("Font path seems invalid and unable to load default texture ! A crash can occur!", Logger::MAJOR);
}
