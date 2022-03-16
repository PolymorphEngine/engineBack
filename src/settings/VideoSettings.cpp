/*
** EPITECH PROJECT, 2022
** VideoSettings.cpp
** File description:
** VideoSettings.cpp
*/


#include "VideoSettings.hpp"
#include "Log/Logger.hpp"
#include "Exceptions/configuration/ConfigurationException.hpp"

Polymorph::Settings::VideoSettings::VideoSettings(
        const std::shared_ptr<XmlNode> &node)
{
    _defaultMode = _initBoolVal(node, "defaultmode");
    _maxFps = _initIntVal(node, "maxfps");
    _fullscreen = _initBoolVal(node, "fullscreen");
    _resizable = _initBoolVal(node, "resizable");
    _bitsPerPixel = _initIntVal(node, "bitsperpixel");
    _resolution = _initResolution(node);
}

bool Polymorph::Settings::VideoSettings::_initBoolVal(
        const std::shared_ptr<XmlNode> &node, const std::string &attrName)
{
    try {
        return node->findAttribute(attrName)->getValueBool();
    } catch (const myxmlpp::AttributeNotFoundException &e) {
        Logger::Log("Video setting is incomplete, cannot find \"" + attrName + "\" attribute", Logger::MINOR);
    } catch (const myxmlpp::IllegalValueException &e) {
        throw ConfigurationException("Video setting is malformated, \"" + attrName + "\" attribute has bad value");
    }
}

int Polymorph::Settings::VideoSettings::_initIntVal(
        const std::shared_ptr<XmlNode> &node, const std::string &attrName)
{
    try {
        return node->findAttribute(attrName)->getValueInt();
    } catch (const myxmlpp::AttributeNotFoundException &e) {
        Logger::Log("Video setting is incomplete, cannot find \"" + attrName + "\" attribute", Logger::MINOR);
    } catch (const myxmlpp::IllegalValueException &e) {
        throw ConfigurationException("Video setting is malformated, \"" + attrName + "\" attribute has bad value");
    }
}

Polymorph::Vector2 Polymorph::Settings::VideoSettings::_initResolution(
        const std::shared_ptr<XmlNode> &node) const
{
    try {
        auto res = node->findChild("Resolution");
        Vector2 toRet;

        toRet.x = res->findAttribute("x")->getValueFloat();
        toRet.y = res->findAttribute("y")->getValueFloat();
        return toRet;
    } catch (const myxmlpp::NodeNotFoundException &e) {
        if (!_fullscreen)
            throw ConfigurationException("Cannot find resolution configuration");
    } catch (const myxmlpp::AttributeNotFoundException &e) {
        Logger::Log("Video setting is incomplete, cannot find \"Resolution\" attribute", Logger::MINOR);
        return {};
    } catch (const myxmlpp::IllegalValueException &e) {
        if (!_fullscreen)
            throw ConfigurationException("Video setting is malformated, \"Resolution\" attribute has bad value");
    }
}

bool Polymorph::Settings::VideoSettings::getDefaultMode() const
{
    return _defaultMode;
}

int Polymorph::Settings::VideoSettings::getMaxFps() const
{
    return _maxFps;
}

bool Polymorph::Settings::VideoSettings::getFullscreen() const
{
    return _fullscreen;
}

bool Polymorph::Settings::VideoSettings::getResizable() const
{
    return _resizable;
}

int Polymorph::Settings::VideoSettings::getBitsPerPixel() const
{
    return _bitsPerPixel;
}

Polymorph::Vector2 Polymorph::Settings::VideoSettings::getResolution() const
{
    return _resolution;
}
