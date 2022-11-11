/*
** EPITECH PROJECT, 2022
** SoundPlayerInitializer.cpp
** File description:
** SoundPlayerInitializer.cpp
*/

#include <Polymorph/Core.hpp>
#include <Polymorph/Debug.hpp>
#include <Polymorph/Factory.hpp>
#include <Polymorph/Config.hpp>
#include <Polymorph/Components.hpp>

Polymorph::SoundPlayerInitializer::SoundPlayerInitializer(Polymorph::Config::XmlComponent &data, GameObject entity) : AComponentInitializer("SoundPlayer", data, entity)
{
}

void Polymorph::SoundPlayerInitializer::build()
{
    data.setProperty("sound", component->sound);
}
