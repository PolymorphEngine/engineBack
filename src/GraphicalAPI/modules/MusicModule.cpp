/*
** EPITECH PROJECT, 2022
** MusicModule.cpp
** File description:
** MusicModule.cpp
*/

#include "GraphicalAPI/modules/MusicModule.hpp"
#include "GraphicalAPI/GraphicalAPI.hpp"

Polymorph::MusicModule::MusicModule(std::shared_ptr<myxmlpp::Node> &data, Config::XmlComponent &manager)
{
    _loadModule();
    manager.setSubProperty("_filePath", data, _filePath);
    _filePath = "./Game/Assets/" + _filePath;
    manager.setSubProperty("_volume", data, _volume);
    manager.setSubProperty("_pitch", data, _pitch);
    _music = std::unique_ptr<is::IMusicModule>(_c_music(_filePath));
    _music->setPitch(_pitch);
    _music->setLoop(false);
    _pitch = false;
}

void Polymorph::MusicModule::play()
{
    _music->play();
}

void Polymorph::MusicModule::stop()
{
    _music->stop();
}

void Polymorph::MusicModule::pause()
{
    _music->pause();
}

void Polymorph::MusicModule::resume()
{
    _music->resume();
}

void Polymorph::MusicModule::setVolume(float volume)
{
    _volume = volume;
    _music->setVolume(volume);
}

void Polymorph::MusicModule::setPitch(float pitch)
{
    _pitch = pitch;
    _music->setPitch(pitch);
}

float Polymorph::MusicModule::getVolume() const
{
    return _volume;
}

float Polymorph::MusicModule::getPitch() const
{
    return _pitch;
}

std::string Polymorph::MusicModule::getFilePath() const
{
    return _filePath;
}

void Polymorph::MusicModule::_loadModule()
{
    if (_c_music)
        return;
    _c_music = GraphicalAPI::loadSymbol<MusicModuleLoader, GraphicalAPI>("createMusicModule");
}

void Polymorph::MusicModule::setLoop(bool loop)
{
    _music->setLoop(loop);
}

void Polymorph::MusicModule::update()
{
    _music->update();
}
