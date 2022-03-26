/*
** EPITECH PROJECT, 2020
** SpriteRendererInitalizer.cpp
** File description:
** SpriteRendererInitalizer.cpp
*/

#include <Polymorph/Core.hpp>
#include <Polymorph/Factory.hpp>
#include <Polymorph/Config.hpp>
#include <Polymorph/Components.hpp>


using namespace Polymorph;

SpriteRendererInitializer::SpriteRendererInitializer(Config::XmlComponent &data, Entity &entity)
        : AComponentInitializer("SpriteRenderer", data, entity)
{

}

void SpriteRendererInitializer::build()
{
    data.setProperty("offset", component->offset);
    data.setProperty("sprite", component->sprite);
}

void SpriteRendererInitializer::reference()
{

}
