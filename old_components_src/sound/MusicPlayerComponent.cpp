/*
** EPITECH PROJECT, 2022
** MusicPlayerComponent.cpp
** File description:
** MusicPlayerComponent.cpp
*/


#include "Core/Component/builtins/sound/MusicPlayerComponent.hpp"
#include "AudioSettings.hpp"

Polymorph::MusicPlayerComponent::MusicPlayerComponent(Polymorph::GameObject gameObject) : Component("MusicPlayer", gameObject)
{
}

void Polymorph::MusicPlayerComponent::play()
{
    music->play();
}

void Polymorph::MusicPlayerComponent::stop()
{
    music->stop();
}

void Polymorph::MusicPlayerComponent::pause()
{
    music->pause();
}

void Polymorph::MusicPlayerComponent::resume()
{
    music->resume();
}

void Polymorph::MusicPlayerComponent::setVolume(float volume)
{
    music->setVolume(volume);
}

float Polymorph::MusicPlayerComponent::getVolume()
{
    return music->getVolume();
}

void Polymorph::MusicPlayerComponent::setPitch(float pitch)
{
    music->setPitch(pitch);
}

float Polymorph::MusicPlayerComponent::getPitch()
{
    return music->getPitch();
}

void Polymorph::MusicPlayerComponent::setLoop(bool loop)
{
    Looping = loop;
    music->setLoop(loop);
}

void Polymorph::MusicPlayerComponent::update()
{
    music->setVolume(Polymorph::Settings::AudioSettings::getMusicVolume() / 100);
    setLoop(Looping);
    music->update();
}

void Polymorph::MusicPlayerComponent::start()
{     
    music->setVolume(Polymorph::Settings::AudioSettings::getMusicVolume() / 100);
    setLoop(Looping);
    if (AutoStart)
        play();
}
