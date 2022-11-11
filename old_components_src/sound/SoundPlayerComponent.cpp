/*
** EPITECH PROJECT, 2022
** SoundPlayerComponent.cpp
** File description:
** SoundPlayerComponent.cpp
*/


#include "Core/Component/builtins/sound/SoundPlayerComponent.hpp"
#include "AudioSettings.hpp"

Polymorph::SoundPlayerComponent::SoundPlayerComponent(Polymorph::GameObject gameObject) : Component("SoundPlayer", gameObject)
{
}

void Polymorph::SoundPlayerComponent::play()
{
    if (!sound->isSoundPlaying())
        sound->play();
}

void Polymorph::SoundPlayerComponent::stop()
{
    sound->stop();
}

void Polymorph::SoundPlayerComponent::pause()
{
    sound->pause();
}

void Polymorph::SoundPlayerComponent::resume()
{
    sound->resume();
}

void Polymorph::SoundPlayerComponent::setVolume(float volume)
{
    sound->setVolume(volume);
}

float Polymorph::SoundPlayerComponent::getVolume()
{
    return sound->getVolume();
}

void Polymorph::SoundPlayerComponent::changeAndPlay(std::shared_ptr<SoundModule> sound)
{
    this->sound = sound;
    play();
}

void Polymorph::SoundPlayerComponent::update()
{
    sound->setVolume(Polymorph::Settings::AudioSettings::getSfxVolume() / 100);
}
