/*
** EPITECH PROJECT, 2022
** AudioSettings.cpp
** File description:
** AudioSettings.cpp
*/


#include "AudioSettings.hpp"
#include "Log/Logger.hpp"

Polymorph::Settings::AudioSettings::AudioSettings(
        std::shared_ptr<XmlNode> node)
{
    _masterValue = _getVolume(node, "mastervolume");
    _musicVolume = _getVolume(node, "musicvolume");
    _sfxVolume = _getVolume(node, "sfxvolume");
}

int
Polymorph::Settings::AudioSettings::_getVolume(std::shared_ptr<XmlNode> node,
                                               const std::string &attrName)
{
    try {
        int val = node->findAttribute(attrName)->getValueInt();

        if (val < 0 || val > 100)
            throw std::runtime_error("Invalid value"); //TODO throw appropriate exception
        return val;
    } catch (const myxmlpp::AttributeNotFoundException &e) {
        Logger::Log("Audio setting is incomplete, cannot find \"" + attrName + "\" attribute", Logger::MINOR);
    } catch (...) {
        Logger::Log("Audio setting is malformated, \"" + attrName + "\" attribute has bad value", Logger::MINOR); //TODO use appropriate level
    }
}

int Polymorph::Settings::AudioSettings::getMasterVolume() {
    return _masterValue;
}

int Polymorph::Settings::AudioSettings::getMusicVolume() {
    return _musicVolume;
}

int Polymorph::Settings::AudioSettings::getSfxVolume() {
    return _sfxVolume;
}
