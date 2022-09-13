/*
** EPITECH PROJECT, 2022
** MusicPlayerInitializer.cpp
** File description:
** MusicPlayerInitializer.cpp
*/

#include <Polymorph/Core.hpp>
#include <Polymorph/Debug.hpp>
#include <Polymorph/Factory.hpp>
#include <Polymorph/Config.hpp>
#include <Polymorph/Components.hpp>

Polymorph::MusicPlayerInitializer::MusicPlayerInitializer(Polymorph::Config::XmlComponent &data, GameObject entity) : AComponentInitializer("MusicPlayer", data, entity)
{
}

void Polymorph::MusicPlayerInitializer::build()
{
    data.setProperty("music", component->music);
    data.setProperty("Looping", component->Looping);
    data.setProperty("AutoStart", component->AutoStart);
}
