/*
** EPITECH PROJECT, 2022
** VideoSettings.cpp
** File description:
** VideoSettings.cpp
*/



#include <polymorph/Settings.hpp>
#include <polymorph/Debug.hpp>

polymorph::engine::Settings::VideoSettings::VideoSettings(
        const std::shared_ptr<XmlNode> &node): _node(node)
{
    _defaultMode = _initBoolVal("defaultmode");
    _maxFps = _initIntVal("maxfps");
    _fullscreen = _initBoolVal("fullscreen");
    _resizable = _initBoolVal("resizable");
    _bitsPerPixel = _initIntVal("bitsperpixel");
    _resolution = _initResolution();
}

bool polymorph::engine::Settings::VideoSettings::_initBoolVal(
        const std::string &attrName)
{
    try {
        return _node->findAttribute(attrName)->getValueBool("true", "false");
    } catch (const myxmlpp::AttributeNotFoundException &e) {
        Logger::Log("Video setting is incomplete, cannot find \"" + attrName +
                    "\" attribute", Logger::MINOR);
    } catch (const myxmlpp::IllegalValueException &e) {
        throw ConfigurationException("Video setting is malformed, \"" + attrName + "\" attribute has bad value");
    }
    return {};
}

int polymorph::engine::Settings::VideoSettings::_initIntVal(
        const std::string &attrName)
{
    try {
        return _node->findAttribute(attrName)->getValueInt();
    } catch (const myxmlpp::AttributeNotFoundException &e) {
        Logger::Log("Video setting is incomplete, cannot find \"" + attrName +
                    "\" attribute", Logger::MINOR);
    } catch (const myxmlpp::IllegalValueException &e) {
        throw ConfigurationException("Video setting is malformed, \"" + attrName + "\" attribute has bad value");
    }
    return {};
}

polymorph::engine::Vector2 polymorph::engine::Settings::VideoSettings::_initResolution() const
{
    try {
        auto res = _node->findChild("Resolution");
        Vector2 toRet;

        toRet.x = res->findAttribute("x")->getValueFloat();
        toRet.y = res->findAttribute("y")->getValueFloat();
        return toRet;
    } catch (const myxmlpp::NodeNotFoundException &e) {
        if (!_fullscreen)
            throw ConfigurationException("Cannot find resolution configuration");
    } catch (const myxmlpp::AttributeNotFoundException &e) {
        Logger::Log(
                "Video setting is incomplete, cannot find \"Resolution\" attribute",
                Logger::MINOR);
        return {};
    } catch (const myxmlpp::IllegalValueException &e) {
        if (!_fullscreen)
            throw ConfigurationException("Video setting is malformated, \"Resolution\" attribute has bad value");
    }
    return {};
}

void polymorph::engine::Settings::VideoSettings::_saveToAttribute(
        const std::shared_ptr<XmlNode> &node,
        const std::string &attrName,
        float value)
{
    try {
        node->findAttribute(attrName)->setValueFloat(value);
    } catch (myxmlpp::AttributeNotFoundException &e) {
        throw ConfigurationException("Failed to save xml data [Video Settings : " + attrName + "]"+ e.baseWhat(), Logger::MAJOR);
    }
}

bool polymorph::engine::Settings::VideoSettings::getDefaultMode() const
{
    return _defaultMode;
}

int polymorph::engine::Settings::VideoSettings::getMaxFps() const
{
    return _maxFps;
}

bool polymorph::engine::Settings::VideoSettings::getFullscreen() const
{
    return _fullscreen;
}

bool polymorph::engine::Settings::VideoSettings::getResizable() const
{
    return _resizable;
}

int polymorph::engine::Settings::VideoSettings::getBitsPerPixel() const
{
    return _bitsPerPixel;
}

polymorph::engine::Vector2 polymorph::engine::Settings::VideoSettings::getResolution() const
{
    return _resolution;
}

void polymorph::engine::Settings::VideoSettings::setDefaultMode(bool mode)
{
    _defaultMode = mode;

    try {
        _node->findAttribute("defaultmode")->setValueBool(mode);
    } catch (const myxmlpp::AttributeNotFoundException &e) {
        _node->addAttribute("defaultmode", std::to_string(mode));
    }
}

void polymorph::engine::Settings::VideoSettings::setMaxFps(int fps)
{
    _maxFps = fps;

    try {
        _node->findAttribute("maxfps")->setValueInt(fps);
    } catch (const myxmlpp::AttributeNotFoundException &e) {
        _node->addAttribute("maxfps", std::to_string(fps));
    }
}

void polymorph::engine::Settings::VideoSettings::setFullscreen(bool fullscreen)
{
    _fullscreen = fullscreen;

    try {
        _node->findAttribute("fullscreen")->setValueBool(fullscreen);
    } catch (const myxmlpp::AttributeNotFoundException &e) {
        _node->addAttribute("fullscreen", std::to_string(fullscreen));
    }
}

void polymorph::engine::Settings::VideoSettings::setResizable(bool resizable)
{
    _resizable = resizable;

    try {
        _node->findAttribute("resizable")->setValueBool(resizable);
    } catch (const myxmlpp::AttributeNotFoundException &e) {
        _node->addAttribute("resizable", std::to_string(resizable));
    }
}

void polymorph::engine::Settings::VideoSettings::setBitsPerPixel(int bitsPerPixel)
{
    _bitsPerPixel = bitsPerPixel;

    try {
        _node->findAttribute("bitsperpixel")->setValueInt(bitsPerPixel);
    } catch (const myxmlpp::AttributeNotFoundException &e) {
        _node->addAttribute("bitsperpixel", std::to_string(bitsPerPixel));
    }
}

void polymorph::engine::Settings::VideoSettings::setResolution(
        polymorph::engine::Vector2 resolution)
{
    _resolution = resolution;
    std::shared_ptr<XmlNode> res;

    try {
        res = _node->findChild("Resolution");
    } catch (const myxmlpp::NodeNotFoundException &e) {
        throw ConfigurationException("Cannot find gravity XML node, save failed");
    }
    _saveToAttribute(res, "x", resolution.x);
    _saveToAttribute(res, "y", resolution.y);
}
