/*
** EPITECH PROJECT, 2022
** AudioSettings.cpp
** File description:
** AudioSettings.cpp
*/


#include "AudioSettings.hpp"
#include "Log/Logger.hpp"

Polymorph::Settings::AudioSettings::AudioSettings(
        const std::shared_ptr<XmlNode> &node) : _node(node)
{
    _masterVolume = _getVolume("mastervolume");
    _musicVolume = _getVolume("musicvolume");
    _sfxVolume = _getVolume("sfxvolume");
}

int
Polymorph::Settings::AudioSettings::_getVolume(const std::string &attrName)
{
    try {
        int val = _node->findAttribute(attrName)->getValueInt();

        if (val < 0 || val > 100)
            throw std::runtime_error("Invalid value"); //TODO throw appropriate exception
        return val;
    } catch (const myxmlpp::AttributeNotFoundException &e) {
        Logger::Log("Audio setting is incomplete, cannot find \"" + attrName + "\" attribute", Logger::MINOR);
    } catch (...) {
        Logger::Log("Audio setting is malformated, \"" + attrName + "\" attribute has bad value", Logger::MINOR); //TODO use appropriate level
    }
    return 100;
}

int Polymorph::Settings::AudioSettings::getMasterVolume() {
    return _masterVolume;
}

int Polymorph::Settings::AudioSettings::getMusicVolume() {
    return _musicVolume;
}

int Polymorph::Settings::AudioSettings::getSfxVolume() {
    return _sfxVolume;
}

void Polymorph::Settings::AudioSettings::setMasterVolume(int vol)
{
    _masterVolume = vol;

    try {
        _node->findAttribute("mastervolume")->setValueInt(vol);
    } catch (const myxmlpp::AttributeNotFoundException &e) {
        _node->addAttribute("mastervolume", std::to_string(vol));
    }
}

void Polymorph::Settings::AudioSettings::setMusicVolume(int vol)
{
    _musicVolume = vol;

    try {
        _node->findAttribute("musicvolume")->setValueInt(vol);
    } catch (const myxmlpp::AttributeNotFoundException &e) {
        _node->addAttribute("musicvolume", std::to_string(vol));
    }
}

void Polymorph::Settings::AudioSettings::setSfxVolume(int vol)
{
    _sfxVolume = vol;

    try {
        _node->findAttribute("sfxvolume")->setValueInt(vol);
    } catch (const myxmlpp::AttributeNotFoundException &e) {
        _node->addAttribute("sfxvolume", std::to_string(vol));
    }
}
