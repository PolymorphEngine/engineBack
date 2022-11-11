/*
** EPITECH PROJECT, 2022
** AudioSettings.cpp
** File description:
** AudioSettings.cpp
*/


#include <polymorph/Settings.hpp>
#include <polymorph/Debug.hpp>

polymorph::engine::Settings::AudioSettings::AudioSettings(
        const std::shared_ptr<XmlNode> &node) : _node(node)
{
    _instance = this;
    _masterVolume = _getVolume("mastervolume");
    _musicVolume = _getVolume("musicvolume");
    _sfxVolume = _getVolume("sfxvolume");
}

float
polymorph::engine::Settings::AudioSettings::_getVolume(const std::string &attrName)
{
    try {
        int val = _node->findAttribute(attrName)->getValueInt();

        if (val < 0 || val > 100)
            throw std::runtime_error("Invalid value"); //TODO throw appropriate exception
        return val;
    } catch (const myxmlpp::AttributeNotFoundException &e) {
        Logger::Log("Audio setting is incomplete, cannot find \"" + attrName +
                    "\" attribute", Logger::MINOR);
    } catch (...) {
        Logger::Log("Audio setting is malformated, \"" + attrName +
                    "\" attribute has bad value", Logger::MINOR); //TODO use appropriate level
    }
    return 100;
}

float polymorph::engine::Settings::AudioSettings::getMasterVolume() {
    return _instance->_masterVolume;
}

float polymorph::engine::Settings::AudioSettings::getMusicVolume()  {
    return _instance->_musicVolume;
}

float polymorph::engine::Settings::AudioSettings::getSfxVolume()  {
    return _instance->_sfxVolume;
}

void polymorph::engine::Settings::AudioSettings::setMasterVolume(float vol)
{
    _instance->_masterVolume = vol;
/*
    try {
        _instance->_node->findAttribute("mastervolume")->setValueFloat(vol);
    } catch (const myxmlpp::AttributeNotFoundException &e) {
        _instance->_node->addAttribute("mastervolume", std::to_string(vol));
    }*/
}

void polymorph::engine::Settings::AudioSettings::setMusicVolume(float vol)
{
    _instance->_musicVolume = vol;
/*
    try {
        _instance->_node->findAttribute("musicvolume")->setValueFloat(vol);
    } catch (const myxmlpp::AttributeNotFoundException &e) {
        _instance->_node->addAttribute("musicvolume", std::to_string(vol));
    }
    */
}

void polymorph::engine::Settings::AudioSettings::setSfxVolume(float vol)
{
    _instance->_sfxVolume = vol;
/*
    try {
        _instance->_node->findAttribute("sfxvolume")->setValueFloat(vol);
    } catch (const myxmlpp::AttributeNotFoundException &e) {
        _instance->_node->addAttribute("sfxvolume", std::to_string(vol));
    }
    */
}
