/*
** EPITECH PROJECT, 2022
** SoundModule.cpp
** File description:
** SoundModule.cpp
*/

#include "GraphicalAPI/modules/SoundModule.hpp"
#include "GraphicalAPI/GraphicalAPI.hpp"

Polymorph::SoundModule::SoundModule(std::shared_ptr<myxmlpp::Node> &data, Config::XmlComponent &manager)
{
    _loadModule();
    manager.setSubProperty("_filePath", data, _filePath);
    _filePath = "./Game/Assets/" + _filePath;
    manager.setSubProperty("_volume", data, _volume);
    _sound = std::unique_ptr<Polymorph::ISoundModule>(_c_sound(_filePath));
    _sound->setVolume(_volume);
}

void Polymorph::SoundModule::play()
{
    _sound->play();
}

void Polymorph::SoundModule::pause()
{
    _sound->pause();
}

void Polymorph::SoundModule::resume()
{
    _sound->resume();
}

void Polymorph::SoundModule::stop()
{
    _sound->stop();
}

void Polymorph::SoundModule::setVolume(float volume)
{
    _volume = volume;
    _sound->setVolume(volume);
}

float Polymorph::SoundModule::getVolume() const
{
    return _volume;
}

std::string Polymorph::SoundModule::getFilePath() const
{
    return _filePath;
}

void Polymorph::SoundModule::_loadModule()
{
    if (_c_sound)
        return;
    _c_sound = GraphicalAPI::loadSymbol<SoundModuleLoader, GraphicalAPI>("createSoundModule");
}

bool Polymorph::SoundModule::isSoundPlaying() const
{
    return _sound->isSoundPlaying();
}

void Polymorph::SoundModule::playMulti()
{
    _sound->playMulti();
}
